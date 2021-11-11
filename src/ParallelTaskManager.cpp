#include "ParallelTaskManager.h"

CParallelTaskManager::CParallelTaskManager() :
	waitingCalculation { 0 }
{

}
CParallelTaskManager::~CParallelTaskManager()
{

}

//reader puts data, task manager deciding how to layout it
void CParallelTaskManager::addInputData(const std::string& inputData)
{

}

//worker gets next available
std::shared_ptr<CTaskNode> CParallelTaskManager::getForHash()
{
	return nullptr;
}

//Writer get ready data
std::shared_ptr<CTaskNode> CParallelTaskManager::getForWrite()
{
	return nullptr;
}

//Reader should call it when reasing is finished
void CParallelTaskManager::indicateReadingFinished()
{

}

//Ending of reading is not equal ending of application. This method indicates that all threads could be stopped
bool CParallelTaskManager::isApplicationActive()
{
	return true;
}