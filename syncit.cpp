#include <iostream>
#include <unistd.h>
#include <csignal>
#include <string>

#include "include/logger.h"

#include "include/filewatcher.h"

bool isForked = false;

void processTerminationHandler(int signum)
{
    Logger::CloseLogFile();
    exit(signum);
}

int daemonize()
{
        pid_t pid, sid;

        pid = fork();
        if ( pid < 0 )
            return EXIT_FAILURE;
        if ( pid > 0)
        {
            std::cout << " Daemon PID : " << pid << std::endl;
            exit(EXIT_SUCCESS);
        }

        // full permissions to files created by the daemon
        //umask(0);

        // Get sid from kernel
        sid = setsid();
        if ( sid < 0 )
            return EXIT_FAILURE;
        else
            std::cout << "SID : " << sid << std::endl;

        // change current directory
        int ret = chdir("/");
        if ( ret < 0 )
        {
            std::cout << "CHDIR failed with code : " << ret << std::endl;
            return EXIT_FAILURE;
        }


        // handle kill signal
        signal(SIGTERM, processTerminationHandler);


        // close standard input/outputs
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        return EXIT_SUCCESS;
}

void AskToDaemonize()
{
        std::cout << "\n Do you want SyncIt to run as a daemon ? [y/n]:  ";
        std::string answer;
        std::cin >> answer;
        std::cout << std::endl << " ... \n" << std::endl;
        int ret;
        if ( answer.compare("y") == 0 )
        {
            ret = daemonize();
            if ( ret != EXIT_SUCCESS )
            {
                std::cout << "\n Error : Daemonization failed !  ( ret = " << ret << " )" << std::endl;
                return;
            }
        }
}

int main (int argc, char* argv[])
{
        std::cout << "\tWelcome to SyncIt !" << std::endl;

//change the process name ( still dangerous )
/* 
        char *process_name = "aaa\0";
        memcpy((void *)argv[0], process_name, sizeof(process_name));
*/

        AskToDaemonize();


        FileWatcher fw;

        if ( !fw.StartedWatching() )
            fw.InitWatch();


        if ( fw.StartedWatching() )
        {
            int checking_frequency = fw.GetClock();

            while ( true )
            {
                sleep(checking_frequency);
                if (fw.FilesHaveChanged())
                    fw.SyncChangedFiles();
            }
        }
        else
        {
            Logger::LogError("no checking");
        }
        

        return EXIT_SUCCESS;
}