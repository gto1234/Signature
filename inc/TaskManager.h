#pragma once
#include <string>
class ITaskManager {
public:
	virtual ~ITaskManager() {};

	//reader puts data, task manager deciding how to layout it
	virtual void addInputData(const std::string& inputData) = 0;
};