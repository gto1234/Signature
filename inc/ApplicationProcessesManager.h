#pragma once
#include <vector>
#include <thread>

#include "ApplicationSettings.h"

#include "TaskWorker.h"
class CApplicationProcessesManager 
{ //TODO: Make singleton
public:
	CApplicationProcessesManager(std::shared_ptr<CApplicationSettings> appSettings);
	~CApplicationProcessesManager();

	void start();
private:
	std::shared_ptr<CApplicationSettings> appSettings;
	std::vector<std::thread> threadStorage;
};