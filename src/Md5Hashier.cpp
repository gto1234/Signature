
#include "Md5Hashier.h"
#include "DebugLogger.h"

CMd5Hashier::CMd5Hashier() {
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}
CMd5Hashier::~CMd5Hashier() {
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}

//TODO: link,Include Boost, get md5 here
std::string CMd5Hashier::calculate(const std::string& incomingBuffer)
{
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
	return std::string("test");
}
