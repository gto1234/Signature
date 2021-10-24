#include <iostream>

#include "DebugLogger.h"

void CDebugLogger::log(const std::string& logMessage)
{
	std::cout << logMessage << std::endl;
}
