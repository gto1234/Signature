#pragma once
#include <string>

#include "TaskManager.h"
//TODO: remove it when parallel will ready

/*
* This task manager is initial implementation to make and easy test common buisness-logic. it is not fully optimized and should replaced by CParallelTaskManager
*/
class CNonParallelTaskManager : public ITaskManager {
public:
	CNonParallelTaskManager();
	~CNonParallelTaskManager();

	//reader puts data, task manager deciding how to layout it
	void addInputData(const std::string& inputData);
private:
};