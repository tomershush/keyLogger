#include "windowManager.h"

/*
* A function that hides the console window of the program.
*/
void windowManager::hideConsoleWindow()
{
	HWND consoleWindow = NULL;

	consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_HIDE);

}
