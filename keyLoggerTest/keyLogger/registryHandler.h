#pragma once
#include <Windows.h>

#define REG_PATH "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run"

class registryHandler
{
public:
	static bool checkRegistry();
	static int addToRegistry();
};

