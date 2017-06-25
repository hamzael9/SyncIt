#include <iostream>
#include <string>

#include "include/logger.h"

#include "include/filewatcher.h"

bool isForked = false;

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

        // close standard input/outputs

        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        return EXIT_SUCCESS;
}

void AskToDaemonize()
{
        std::cout << " Do you want SyncIt to run as a daemon ? [y/n]:  ";
        std::string answer;
        std::cin >> answer;
        std::cout << std::endl << " ... " << std::endl;
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

int main ()
{
        std::cout << "\tWelcome to SyncIt !" << std::endl;

        AskToDaemonize();

        //FileWatcher fw;
        
        while ( true )
        {
            sleep(2);
            Logger::LogInfo("running");
            //if ( !fw.IsWatching() )
            //    fw.StartWatch();
        }

        return EXIT_SUCCESS;
}