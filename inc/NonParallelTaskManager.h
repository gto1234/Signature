#pragma once
#include <string>
#include <memory>

#include "TaskManager.h"
#include "TaskNode.h"
//TODO: remove it when parallel will ready

/*
* This task manager is initial implementation to make and easy test common buisness-logic. it is not fully optimized and should replaced by CParallelTaskManager
*/
class CNonParallelTaskManager : public ITaskManager 
{
public:
	CNonParallelTaskManager();
	~CNonParallelTaskManager();

	//reader puts data, task manager deciding how to layout it
	void addInputData(const std::string& inputData);

	//worker gets next available
	std::shared_ptr<CTaskNode> getForHash();

	//Writer get ready data
	std::shared_ptr<CTaskNode> getForWrite();

	//Reader should call it when reasing is finished
	void indicateReadingFinished();

	//Ending of reading is not equal ending of application. This method indicates that all threads could be stopped
	bool isApplicationActive();

	unsigned long getPossibleCountOfWorkerThreads();
private:
	bool readingFinished;
	bool stopApplicationFlag;
	std::shared_ptr<CTaskNode> singleTaskNode;

};