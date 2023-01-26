#include "logManager.h"


/*
* A function that returns the singleton's instance.
* There is only one instance of the log manager and it returns it.
*/
logManager* logManager::getLogManager()
{
    if (manager == nullptr)
        manager = new logManager();

    return manager;
}

/*
* A function that creates the log file.
*/
void logManager::createLogFile()
{
    std::ofstream logFile(LOG_FILE);
    logFile.close();
}

/*
* A function that writes a single character to the log file.
*/
void logManager::writeCharToLog(const char charToLog)
{
    std::ofstream logFile(LOG_FILE, std::ios_base::app);

    if(charToLog != 0)
        logFile << charToLog;
}

// Destructor.
logManager::~logManager()
{
}
