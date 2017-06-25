#include <string>
#include <vector>

#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


struct watched_file
{
    const char* file_name;
    time_t last_mtime;
};

class FileWatcher
{
    private:

        struct stat m_file_stat; // buffer where to store stat sys call result

        static std::vector<watched_file> m_watched_files;

        bool LoadFilesToWatch();

        bool m_iswatching;

    public:

        FileWatcher();

        bool StartWatch();

        bool IsWatching();

};