#pragma once
#include <string>
#include <memory>

#include "TaskManager.h"
#include "TaskNode.h"

/*
* This task manager is initial implementation to make and easy test common buisness-logic. it is not fully optimized and replaced by CParallelTaskManager. Still alive just because it was implemented
*/
class CNonParallelTaskManager : public ITaskManager 
{
public:
	CNonParallelTaskManager();

	~CNonParallelTaskManager();

	//reader puts data, task manager deciding how to layout it
	void addInputData(const std::vector<uint8_t>& inputData);

	//worker gets next available
	std::shared_ptr<CTaskNode> getForHash();

	//Writer get ready data
	std::shared_ptr<CTaskNode> getForWrite();

	//Reader should call it when reasing is finished
	void indicateReadingFinished();

	//Ending of reading is not equal ending of application. This method indicates that all threads could be stopped
	bool isApplicationActive();

	//Get count of ptimal worker threads count
	unsigned long getPossibleCountOfWorkerThreads();

	//Indicate that all thread should stop (exception happend)
	void forceStop();

private:
	bool readingFinished;
	bool stopApplicationFlag;
	std::shared_ptr<CTaskNode> singleTaskNode;
};