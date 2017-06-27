#include <string>
#include <vector>

//#include <sys/stat.h>
//#include <unistd.h>
#include <sys/stat.h>
#include <ctime>


struct watched_file
{
    const char* file_name;
    time_t last_mtime;
};

class FileWatcher
{
    private:

        struct stat m_stat; // buffer where to store stat sys call result

        std::vector<watched_file> m_watched_files; 

        void LoadFilesToWatch();

        void CheckForChanges();

        bool m_iswatching;

        bool m_changesExist;

        std::string CONFIG_FILE_PATH; 

        int CLOCK;

    public:

        FileWatcher();

        int getClock(); // getter for the clock

        void InitWatch();

        bool StartedWatching();

        bool FileChanged();

        void SyncChangedFiles();

};