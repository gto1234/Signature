#include <iostream>

#include "FileReader.h"
#include "File.h"
#include "DebugLogger.h"

CFileReader::CFileReader(std::shared_ptr<ITaskManager> taskManagerPointer, const std::string& fileName, unsigned long int partitionSize) : 
	taskManagerPointer{ taskManagerPointer }, 
	fileName{ fileName },
	partitionSize{partitionSize}
{
}

CFileReader::~CFileReader()
{
}

void CFileReader::read() 
{
	CFile inputFile(this->fileName, CFile::EOpenMode::READ);
	unsigned long int s = 0;

	try {
		while (!inputFile.endReached()) {
			std::string inputData = inputFile.read(this->partitionSize);
			s += inputData.length();
			this->taskManagerPointer->addInputData(inputData);
		}
		this->taskManagerPointer->indicateReadingFinished();
	}
	catch (CFileSafeException &readexcept) {
		//TODO: push it to exceptionlist, stop program
		std::cout << "exception met";
	}
}