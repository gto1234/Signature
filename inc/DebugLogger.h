#pragma once
#include <string>

/*
* Used for quick out message to cout. Used during debug
*/
class CDebugLogger 
{
public:
	static void log(const std::string& logMessage);
};

