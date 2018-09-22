#include <iostream>

using namespace std; //Not good practise!!

class Log
{
public:
    //const int error = 0, warning = 1, info = 2;
    enum {
        error = 0, warning, info
    };
private:
    int m_logLevel = info; //m_ prefix tells the member is private
public:
    void SetLevel(int level)
    {
        m_logLevel = level;
    }

    void Warn(const char* message)
    {
        if(m_logLevel <= warning)
            cout << "[WARNING]: " << message << endl;
    }

    void Info (const char* message)
    {
        if(m_logLevel <= info)
            cout << "[INFO]: " << message << endl;
    }

    void Error(const char* message)
    {
        if(m_logLevel <= error)
            cout << "[ERROR]: " << message << endl;
    }
};

int main ()
{
    Log log;
    log.SetLevel(log.error); //Set log level here

    //POC
    log.Warn("This is a warning");
    log.Info("This is an info");
    log.Error("This is an error");

    return 0;
}
