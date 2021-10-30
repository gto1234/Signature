#include "TaskWorker.h"
#include "DebugLogger.h"

CTaskWorker::CTaskWorker(std::shared_ptr<ITaskManager> taskManagerPointer) : taskManagerPointer{taskManagerPointer} {
}
CTaskWorker::~CTaskWorker() {
}

void CTaskWorker::processTaskNode() {
	do
	{
		std::shared_ptr<CTaskNode> taskNode = this->taskManagerPointer->getForHash();
		
		if (taskNode == nullptr) {
			
		}
		else {
			taskNode->calculate();
		}
	} while (this->taskManagerPointer->isApplicationActive());
}