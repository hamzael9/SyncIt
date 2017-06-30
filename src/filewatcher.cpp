#include <string>
#include <fstream>

#include "../include/filewatcher.h"
#include "../include/logger.h"
#include "../include/filesynchronizer.h"

//std::vector<watched_file> FileWatcher::m_watched_files;


FileWatcher::FileWatcher()
{
    m_watched_files = {};
    CONFIG_FILE_PATH = "/Users/hamza/Work/programming/SyncIt/config";
    m_clock = 5;
    LoadFilesToWatch();
    m_iswatching = false;
}

int FileWatcher::GetClock()
{
    return m_clock;
}

void FileWatcher::LoadFilesToWatch()
{
    /*
    watched_file f1,f2;
    f1.file_name = "/Users/hamza/Work/programming/SyncIt/tests/file1";
    f2.file_name = "/Users/hamza/Work/programming/SyncIt/tests/file2";
    FileWatcher::m_watched_files.push_back(f1);
    FileWatcher::m_watched_files.push_back(f2);
    //FileWatcher::m_watched_files.push_back();
    */

    std::ifstream config_file(CONFIG_FILE_PATH);
    std::string line;
    while ( std::getline(config_file, line) )
    {
        watched_file f;
        f.file_name = line;
        m_watched_files.push_back(f);
    }

}

void FileWatcher::InitWatch()
{
    Logger::LogInfo("[FILE WATCHER] : Start Watching files");

    m_iswatching = false;
    for (auto &file : m_watched_files)
    {
        Logger::LogInfo("File Init : " + file.file_name );

        if (stat(file.file_name.c_str(),&m_stat)  == 0 )
        {
            file.last_mtime = m_stat.st_mtime;
            m_iswatching = true;
        }
        else
        {
            Logger::LogError("Stat Error ! ");
        }
    }
}

bool FileWatcher::StartedWatching()
{
    return m_iswatching;
}

bool FileWatcher::FilesHaveChanged()
{
    CheckForChanges();
    return m_changesExist;
}

void FileWatcher::CheckForChanges()
{
    // TODO: Check for changes
    m_changesExist = false;
    for (auto &file : FileWatcher::m_watched_files)
    {
        Logger::LogInfo("Check For Changes : " + file.file_name );
        if ( stat(file.file_name.c_str(),&m_stat) == 0 )
        {
            if ( file.last_mtime < m_stat.st_mtime )
            {
                file.last_mtime = m_stat.st_mtime;
                Logger::LogInfo("[FILE WATCHER] : " + file.file_name + " changed !");
                m_files_to_sync.push_back(file.file_name);
                m_changesExist = true;
            }
        }
    }
}

void FileWatcher::SyncChangedFiles()
{
    // TODO: Implement it using threads
    Logger::LogInfo("[FILE WATCHER] : Syncing Changed Files");
    for (auto f : m_files_to_sync)
    {
        FileSynchronizer fs (f);
        fs.Sync();
    }
}