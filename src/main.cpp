#include <iostream>
#include "ApplicationProcessesManager.h"
#include "CommandLineProcessor.h"
#include "ExceptionStorage.h"

int main(int argc, char* argv[]) 
{
	CCommandLineProcessor commandLineProcessor;
	std::shared_ptr<CApplicationSettings> appSettings = nullptr;

	try {
		appSettings = commandLineProcessor.parse(argc, argv);
		CApplicationProcessesManager applicationProcessesManager(appSettings);
		applicationProcessesManager.start();
	}
	catch (CCommadLineArgumentsAnalyzeException& parseException)
	{
		std::cout << parseException.what() << std::endl;
		CCommandLineProcessor::showInfoUsage();
		return 0;
	}	
	catch (std::exception& commonException)
	{
		CExceptionStorage::getInstance().push(commonException);
	}

	//Show List exceptions (if it occur). If exception have not effect to result of execution then it will not placed here
	CExceptionStorage::getInstance().printAll();

	return 0;
}