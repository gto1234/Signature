#include "NonParallelTaskManager.h"
#include "DebugLogger.h"
CNonParallelTaskManager::CNonParallelTaskManager() {
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));

}

CNonParallelTaskManager::~CNonParallelTaskManager() {
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}

void CNonParallelTaskManager::addInputData(const std::string& inputData)
{
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
	//TODO: implement adding
}

