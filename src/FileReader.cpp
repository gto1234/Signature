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
	CFile inputFile(this->fileName, "rt");

	try {
		while (!inputFile.endReached()) {
			std::string inputData = inputFile.read(this->partitionSize);
			this->taskManagerPointer->addInputData(inputData);
		}
		this->taskManagerPointer->indicateReadingFinished();
	}
	catch (CFileSafeException &readexcept) {
		//TODO: push it to exceptionlist, stop program
	}
}