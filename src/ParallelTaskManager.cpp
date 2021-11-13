#include <windows.h>
#include <iostream>
#include <thread>

#include "ParallelTaskManager.h"
#include "CriticalSectionCreator.h"
#include "CustomLocker.h"


CParallelTaskManager::CParallelTaskManager() : 
	readingFinished{ false },
	forcedStop{ false }
{
	this->taskNodesCriticalSectionIn = CCriticalSectionCreator::create();
	this->taskNodesCriticalSectionOut = CCriticalSectionCreator::create();
	this->forceStopCriticalSection = CCriticalSectionCreator::create();

	countPossibleAmountOfWorkerThreads();
	limitBufferNodesSize = 2 * this->countPossibleWorkerThreads;
	
}
CParallelTaskManager::~CParallelTaskManager()
{

}

//reader puts data, task manager deciding how to layout it
void CParallelTaskManager::addInputData(const std::vector<uint8_t>& inputData)
{
	//add check for max buffer reached
	//If reading faster than we should wait, else allocated memory will growth
	while ((this->taskNodesIn.size() > limitBufferNodesSize) || (this->taskNodesOut.size() > limitBufferNodesSize));

	CCustomLocker inLocker(this->taskNodesCriticalSectionIn); //lock access for In deque
	CCustomLocker outLocker(this->taskNodesCriticalSectionOut); //lock access for Out deque

	//Create new node and add it for both In and Out deque
	try
	{
		std::shared_ptr<CTaskNode> newNode = std::make_shared<CTaskNode>(inputData);
		this->taskNodesIn.emplace_back(newNode);
		this->taskNodesOut.emplace_back(newNode);
	}
	catch (std::exception& commonException)
	{
		CExceptionStorage::getInstance().push(commonException);
		this->forceStop();
	}

}

//worker gets next available
std::shared_ptr<CTaskNode> CParallelTaskManager::getForHash()
{
	if (this->taskNodesIn.empty()) //To not make over-busy critical section
		return nullptr;

	CCustomLocker inLocker(this->taskNodesCriticalSectionIn);
	//Safe but we must ensured that no any other thread become first
	if (this->taskNodesIn.empty())
		return nullptr;

	std::shared_ptr<CTaskNode> ret = this->taskNodesIn.front();
	this->taskNodesIn.pop_front();	
	return ret;
}

//Writer get ready data
std::shared_ptr<CTaskNode> CParallelTaskManager::getForWrite()
{
	if (this->taskNodesOut.empty()) //To not make over-busy critical section
		return nullptr;

	CCustomLocker outLocker(this->taskNodesCriticalSectionOut); //lock access

	if (this->taskNodesOut.empty()) //Safe but we must ensured that no any other thread become first
		return nullptr;

	std::shared_ptr<CTaskNode> frontTaskNode = this->taskNodesOut.front();

	if (frontTaskNode->getState() == CTaskNode::EState::HASH_CALCULATED)
	{		
		this->taskNodesOut.pop_front();
		return frontTaskNode;
	}
	return nullptr;
}

//Reader should call it when reasing is finished
void CParallelTaskManager::indicateReadingFinished()
{
	this->readingFinished = true;
}

//Ending of reading is not equal ending of application. This method indicates that all threads could be stopped
bool CParallelTaskManager::isApplicationActive()
{
	return !(((this->readingFinished) && (this->taskNodesIn.empty()) && (this->taskNodesOut.empty())) || (this->forcedStop));
	
}

void CParallelTaskManager::countPossibleAmountOfWorkerThreads()
{
	SYSTEM_INFO systemInfoStructure;

	GetSystemInfo(&systemInfoStructure);

	unsigned long ret = systemInfoStructure.dwNumberOfProcessors;
	if (ret >= 3) ret -= 2; //Writer and Reader threads place
	else ret = 1;

	this->countPossibleWorkerThreads = ret;
}

unsigned long CParallelTaskManager::getPossibleCountOfWorkerThreads()
{
	return this->countPossibleWorkerThreads;
}

void CParallelTaskManager::forceStop() 
{
	CCustomLocker forceStopLocaker(this->forceStopCriticalSection);
	this->forcedStop = true;
}