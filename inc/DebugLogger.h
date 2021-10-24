#pragma once
#include <string>

class CDebugLogger {
public:
	static void log(const std::string& logMessage);
};

/*
CDebugLogger::log("Called " + std::string(__FUNCSIG__));
CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
*/