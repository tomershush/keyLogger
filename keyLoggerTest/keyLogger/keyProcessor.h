#pragma once
#include <iostream>
#include <Windows.h>

#define LOWEST_PRINTABLE '!'
#define HIGHEST_PRINTABLE '~'

/*
* A static class that processes and formats 
* keystrokes to readable or useful formats.
*/

class keyProcessor
{
public:
	static char filterPrintableChar(char keyChar);
	static char formatShiftedKeys(char keyChar);
	static char convertToLowerCase(char letter);
	static std::string convertSpecialChar(int virtualCode);
};

