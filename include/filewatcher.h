#include <string>
#include <vector>

//#include <sys/stat.h>
//#include <unistd.h>
#include <sys/stat.h>
#include <ctime>


struct watched_file
{
    std::string file_name;
    time_t last_mtime;
};

class FileWatcher
{
    private:

        struct stat m_stat; // buffer where to store stat sys call result

        std::vector<watched_file> m_watched_files;

        std::vector<std::string> m_files_to_sync;

        void LoadFilesToWatch();

        void CheckForChanges();

        bool m_iswatching;

        bool m_changesExist;

        std::string CONFIG_FILE_PATH; 

        int m_clock;

    public:

        FileWatcher();

        int GetClock(); // getter for the clock

        void InitWatch();

        bool StartedWatching();

        bool FilesHaveChanged();

        void SyncChangedFiles();

};