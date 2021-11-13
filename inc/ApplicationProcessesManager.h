#pragma once
#include <vector>
#include <thread>

#include "ApplicationSettings.h"

/*
* Runs application threads, joining its completion
*/
class CApplicationProcessesManager 
{
public:
	/*Initialize application by incoming settings*/
	CApplicationProcessesManager(std::shared_ptr<CApplicationSettings> appSettings);

	~CApplicationProcessesManager();

	/*start target application execution*/
	void start();

private:
	std::shared_ptr<CApplicationSettings> appSettings;
	std::vector<std::thread> threadStorage;
};