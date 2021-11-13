#pragma once
#include <memory>

#include "TaskManager.h"

class CTaskWorker 
{
public:
	CTaskWorker(std::shared_ptr<ITaskManager> taskManagerPointer);

	~CTaskWorker();

	/*Thread entrypoint method*/
	void processTaskNode();

private:
	std::shared_ptr<ITaskManager> taskManagerPointer;
};