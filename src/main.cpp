#include <iostream>
#include "ApplicationProcessesManager.h"
#include "CommandLineProcessor.h"

int main(int argc, char* argv[]) 
{
	CCommandLineProcessor commandLineProcessor;
	std::shared_ptr<CApplicationSettings> appSettings = nullptr;
	try {
		appSettings = commandLineProcessor.parse(argc, argv);
	}
	catch (CCommadLineArgumentsAnalyzeException& parseException)
	{
		std::cout << parseException.what() << std::endl;
		CCommandLineProcessor::showInfoUsage();
		return 0;
	}
	CApplicationProcessesManager applicationProcessesManager(appSettings);
	applicationProcessesManager.start();

	return 0;
}