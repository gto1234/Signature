#pragma once
#include <memory>
#include <deque>
#include <vector>

#include "TaskManager.h"
#include "CustomCriticalSection.h"
#include "ExceptionStorage.h"


class CParallelTaskManager : public ITaskManager
{
public:
	CParallelTaskManager();

	~CParallelTaskManager();

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
	void countPossibleAmountOfWorkerThreads();

	std::deque<std::shared_ptr<CTaskNode>> taskNodesIn;
	std::deque<std::shared_ptr<CTaskNode>> taskNodesOut;

	std::shared_ptr<ICustomCriticalSection> taskNodesCriticalSectionIn;
	std::shared_ptr<ICustomCriticalSection> taskNodesCriticalSectionOut;
	std::shared_ptr<ICustomCriticalSection> forceStopCriticalSection;

	bool readingFinished;
	unsigned long countPossibleWorkerThreads;
	unsigned long limitBufferNodesSize;
	bool forcedStop;
};

