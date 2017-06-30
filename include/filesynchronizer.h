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
            m_remote_server = "192.168.56.101";
        }

        void Sync()
        {
            // exec scp
            std::string commande = "scp " + m_file_path + " ubuntu@" + m_remote_server + ":~/";
            std::system(commande.c_str());
        }

};