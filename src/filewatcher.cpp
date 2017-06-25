#include "../include/filewatcher.h"
#include "../include/logger.h"


std::vector<watched_file> FileWatcher::m_watched_files;


FileWatcher::FileWatcher()
{
    LoadFilesToWatch();
}

bool FileWatcher::LoadFilesToWatch()
{
    watched_file f;
    f.file_name = "file1";
    FileWatcher::m_watched_files.push_back(f);
    //FileWatcher::m_watched_files.push_back();
    return true;
}

void FileWatcher::InitWatch()
{
    Logger::LogInfo("[FILE WATCHER] : Start Watching files");
    m_iswatching = true;
}

bool FileWatcher::StartedWatching()
{
    return m_iswatching;
}

bool FileWatcher::FileChanged()
{
    CheckForChanges();
    return m_changesExist;
}

void FileWatcher::CheckForChanges()
{
    // TODO: Check for changes
    m_changesExist = true;
}

void FileWatcher::SyncChangedFiles()
{
    // TODO: Implement it using threads

    Logger::LogInfo("[FILE WATCHER] : Syncing Changed Files");
}