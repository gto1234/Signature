#include "TaskWorker.h"
#include "DebugLogger.h"



CTaskWorker::CTaskWorker(std::shared_ptr<ITaskManager> taskManagerPointer) : 
	taskManagerPointer { taskManagerPointer },
	counterPartitions { 0 }
{
}
CTaskWorker::~CTaskWorker() 
{
}

void CTaskWorker::processTaskNode() 
{
	do
	{		
		std::shared_ptr<CTaskNode> taskNode = this->taskManagerPointer->getForHash();
		
		if (taskNode == nullptr) 
		{
		}
		else 
		{			
			taskNode->calculate();
			this->counterPartitions++;
		}
	} while (this->taskManagerPointer->isApplicationActive());
}

unsigned long int CTaskWorker::getCounterPartition()
{
	return this->counterPartitions;
}