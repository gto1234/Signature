#include <memory>

#include "ApplicationProcessesManager.h"

#include "DebugLogger.h"
#include "FileReader.h"
#include "NonParallelTaskManager.h"

CApplicationProcessesManager::CApplicationProcessesManager() {
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}

CApplicationProcessesManager::~CApplicationProcessesManager() {
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}

void CApplicationProcessesManager::start() {
	std::shared_ptr<ITaskManager> taskManager = std::make_shared<CNonParallelTaskManager>();
	std::shared_ptr<IReader> fileReader = std::make_shared<CFileReader>(taskManager, 12); //TODO: unbind constant

	fileReader->read();
	
	//fileReader->
}
