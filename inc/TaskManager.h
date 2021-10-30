#pragma once
#include <string>

#include "TaskNode.h"
class ITaskManager 
{
public:
	virtual ~ITaskManager() {};
	
	//reader puts data, task manager deciding how to layout it
	virtual void addInputData(const std::string& inputData) = 0;
	
	//worker gets next available
	virtual std::shared_ptr<CTaskNode> getForHash() = 0;

	//Writer get ready data
	virtual std::shared_ptr<CTaskNode> getForWrite() = 0;
	
	//Reader should call it when reasing is finished
	virtual void indicateReadingFinished() = 0;
	
	//Ending of reading is not equal ending of application. This method indicates that all threads could be stopped
	virtual bool isApplicationActive() = 0;
};