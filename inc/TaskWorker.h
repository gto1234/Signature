#pragma once
#include <memory>

#include "TaskManager.h"

class CTaskWorker 
{
public:
	CTaskWorker(std::shared_ptr<ITaskManager> taskManagerPointer);
	~CTaskWorker();

	void processTaskNode();
	unsigned long int getCounterPartition();
private:
	std::shared_ptr<ITaskManager> taskManagerPointer;
	unsigned long int counterPartitions;
};