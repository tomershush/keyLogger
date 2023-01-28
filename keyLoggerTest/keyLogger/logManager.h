#pragma once
#include <fstream>
#include <iostream>


#define LOG_FILE "log.txt"

/*
* A class that manages the log file.
* The log file contains all the recorded keystrokes.
*/

class logManager
{
public:
	static logManager* getLogManager();
	void createLogFile();
	void writeCharToLog(const std::string charToLog);

	logManager(const logManager& obj)= delete;
	~logManager();

private:
	static logManager* manager;
	logManager() {}
	

};

