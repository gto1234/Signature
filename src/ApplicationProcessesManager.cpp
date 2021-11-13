#include <memory>
#include <list>
#include <iostream>

#include "ApplicationProcessesManager.h"

#include "DebugLogger.h"
#include "FileReader.h"
#include "TaskWorker.h"
#include "NonParallelTaskManager.h"
#include "ParallelTaskManager.h"
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
	//std::shared_ptr<ITaskManager> taskManager = std::make_shared<CNonParallelTaskManager>();
	
	std::shared_ptr<ITaskManager> taskManager = std::make_shared<CParallelTaskManager>();

	std::shared_ptr<IReader> fileReader = std::make_shared<CFileReader>(taskManager, this->appSettings->getInputFileName(), this->appSettings->getBlockSize());
	std::shared_ptr<IWriter> writer = std::make_shared<CFileWriter>(taskManager, this->appSettings->getOutputFileName());

	std::list<std::shared_ptr<CTaskWorker>> workersList;
	unsigned long workersCount = taskManager->getPossibleCountOfWorkerThreads();
	for (size_t indexWorkerThread = 0; indexWorkerThread < workersCount; indexWorkerThread++)
	{
		std::shared_ptr<CTaskWorker> worker = std::make_shared<CTaskWorker>(taskManager);
		workersList.emplace_back(worker);
	}

	

	this->threadStorage.emplace_back(std::thread(runThreadReader, fileReader));	
	this->threadStorage.emplace_back(std::thread(runThreadWriter, writer));

	for(std::shared_ptr<CTaskWorker> worker : workersList)
	{
		this->threadStorage.emplace_back(std::thread(runThreadWorker, worker));
	}


	for (std::thread& itThread : this->threadStorage) {
		itThread.join();
	}
	/*std::cout << std::endl;
	unsigned long partitionSizeTotal = 0;
	for (std::shared_ptr<CTaskWorker> worker : workersList)
	{
		partitionSizeTotal += worker->getCounterPartition();
		std::cout << worker->getCounterPartition() << std::endl;
	}
	std::cout << partitionSizeTotal;*/
}


