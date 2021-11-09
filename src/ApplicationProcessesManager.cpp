#include <memory>

#include "ApplicationProcessesManager.h"

#include "DebugLogger.h"
#include "FileReader.h"
#include "TaskWorker.h"
#include "NonParallelTaskManager.h"
#include "FileWriter.h"

CApplicationProcessesManager::CApplicationProcessesManager(std::shared_ptr<CApplicationSettings> appSettings) : appSettings { appSettings }
{	
}

CApplicationProcessesManager::~CApplicationProcessesManager() 
{

}

//Non-member function represents entrypoint for reader instance
void runThreadReader(std::shared_ptr<IReader> reader)
{
	reader->read();
}

void runThreadWorker(std::shared_ptr<CTaskWorker> worker) 
{
	worker->processTaskNode();
}

void runThreadWriter(std::shared_ptr<IWriter> writer) 
{
	writer->write();
}

void CApplicationProcessesManager::start() 
{
	std::shared_ptr<ITaskManager> taskManager = std::make_shared<CNonParallelTaskManager>();
	std::shared_ptr<IReader> fileReader = std::make_shared<CFileReader>(taskManager, this->appSettings->getInputFileName(), this->appSettings->getBlockSize());

	//Formirate dynamicly cout of workers
	std::shared_ptr<CTaskWorker> worker = std::make_shared<CTaskWorker>(taskManager);

	std::shared_ptr<IWriter> writer = std::make_shared<CFileWriter>(taskManager, this->appSettings->getOutputFileName());

	this->threadStorage.emplace_back(std::thread(runThreadReader, fileReader));
	this->threadStorage.emplace_back(std::thread(runThreadWorker, worker));
	this->threadStorage.emplace_back(std::thread(runThreadWriter, writer));


	for (std::thread& itThread : this->threadStorage) {
		itThread.join();
	}
}


