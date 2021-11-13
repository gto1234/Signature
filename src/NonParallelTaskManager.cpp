#include "NonParallelTaskManager.h"
#include "DebugLogger.h"
CNonParallelTaskManager::CNonParallelTaskManager() : stopApplicationFlag{ false }, readingFinished{ false } 
{
	singleTaskNode = std::make_shared<CTaskNode>();
}

CNonParallelTaskManager::~CNonParallelTaskManager() 
{
}

void CNonParallelTaskManager::addInputData(const std::vector<uint8_t>& inputData)
{
	while (singleTaskNode->getState() != CTaskNode::EState::ON_IDLE)
		continue;

	singleTaskNode->setInputData(inputData);
}

std::shared_ptr<CTaskNode> CNonParallelTaskManager::getForHash() 
{

	while ((!this->readingFinished) && (singleTaskNode->getState() != CTaskNode::EState::NEW_VALUE));

	if (singleTaskNode->getState() == CTaskNode::EState::NEW_VALUE) {
		return this->singleTaskNode;
	}
	else {
		return nullptr;
	}	
}

//Writer get ready data
std::shared_ptr<CTaskNode> CNonParallelTaskManager::getForWrite() 
{
	while ((!this->readingFinished) && (singleTaskNode->getState() != CTaskNode::EState::HASH_CALCULATED));

	if (singleTaskNode->getState() == CTaskNode::EState::HASH_CALCULATED) {
		return this->singleTaskNode;
	}
	else {
		return nullptr;
	}
}

//Reader should call it when reading is finished
void CNonParallelTaskManager::indicateReadingFinished() 
{
	this->readingFinished = true;
}

bool CNonParallelTaskManager::isApplicationActive()
{
	if (this->readingFinished && this->singleTaskNode->getState() == CTaskNode::EState::ON_IDLE) {
		this->stopApplicationFlag = true;
	}
	return !this->stopApplicationFlag;
}

unsigned long CNonParallelTaskManager::getPossibleCountOfWorkerThreads()
{
	return 1;
}

//Indicate that all thread should stop (exception happend)
void CNonParallelTaskManager::forceStop()
{
	this->stopApplicationFlag = true;
}