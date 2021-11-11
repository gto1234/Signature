#pragma once
#include <deque>

#include "TaskManager.h"

class CParallelTaskManager : public ITaskManager
{
public:
	CParallelTaskManager();
	~CParallelTaskManager();

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
private:
	std::deque<CTaskNode> nodes;
	size_t waitingCalculation;
};

