#pragma once
#include <vector>
#include <thread>

#include "TaskWorker.h"
class CApplicationProcessesManager { //TODO: Make singleton
public:
	CApplicationProcessesManager();
	~CApplicationProcessesManager();

	void start();
private:
	std::vector<std::thread> threadStorage;
};