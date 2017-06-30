#include <string>



class FileSynchronizer
{

    private:
        std::string m_file_path;
        std::string m_remote_server;

    public:
        FileSynchronizer(std::string p_file_path)
        {
            m_file_path = p_file_path;
            m_remote_server = "127.0.0.1";
        }

        void Sync()
        {
            
        }

};