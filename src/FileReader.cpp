#include "FileReader.h"
#include "File.h"
#include "DebugLogger.h"

CFileReader::CFileReader(std::shared_ptr<ITaskManager> taskManagerPointer, unsigned long int partitionSize) : taskManagerPointer{ taskManagerPointer }, partitionSize{partitionSize}
{
}

CFileReader::~CFileReader()
{
}

void CFileReader::read() {
	CFile inputFile("d:\\in.txt", "rt"); //TODO: set path

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