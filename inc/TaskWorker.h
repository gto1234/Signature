#pragma once
#include <memory>

#include "TaskManager.h"

class CTaskWorker {
public:
	CTaskWorker(std::shared_ptr<ITaskManager> taskManagerPointer);
	~CTaskWorker();

	void processTaskNode();

private:
	std::shared_ptr<ITaskManager> taskManagerPointer;
};