#include "../include/filewatcher.h"
#include "../include/logger.h"


std::vector<watched_file> FileWatcher::m_watched_files;


FileWatcher::FileWatcher()
{
}

bool FileWatcher::LoadFilesToWatch()
{
    watched_file f;
    f.file_name = "file1";
    FileWatcher::m_watched_files.push_back(f);
    //FileWatcher::m_watched_files.push_back();
    return true;
}

bool FileWatcher::StartWatch()
{
    Logger::LogInfo("[FILE WATCHER] : Start Watching files");
    return true;
}