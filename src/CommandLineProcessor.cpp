#include <string>
#include <unordered_map>
#include <iostream>

#include "CommandLineProcessor.h"

CCommandLineProcessor::CCommandLineProcessor()
{
}

void CCommandLineProcessor::showInfoUsage()
{
	std::cout << "Please use program follow" << std::endl << "Signature <input file> <output file> [block size in bytes]" << std::endl;
}

std::shared_ptr<CApplicationSettings> CCommandLineProcessor::parse(int argumentsCount, char* arguments[])
{
	if ((argumentsCount < 3) || (argumentsCount > 4))
	{
		throw CCommadLineArgumentsAnalyzeException("Incorrect cout of arguments");
	}

	std::shared_ptr<CApplicationSettings> retApplicationSettings = std::make_shared<CApplicationSettings>();

	retApplicationSettings->setInputFileName(std::string(arguments[1]));
	retApplicationSettings->setOutputFileName(std::string(arguments[2]));

	if (argumentsCount == 4) {
		std::string stringPresentationBlockSize(arguments[3]);
		size_t blockSize = 0;
		try 
		{
			blockSize = std::stoi(stringPresentationBlockSize);
		}
		catch (...)
		{
			throw CCommadLineArgumentsAnalyzeException("Incorrect block size value");
		}
		retApplicationSettings->setBlockSize(blockSize);
	}

	return retApplicationSettings;
}

