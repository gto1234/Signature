#include "FileReader.h"
#include "File.h"
#include "DebugLogger.h"

CFileReader::CFileReader(std::shared_ptr<ITaskManager> taskManagerPointer, unsigned long int partitionSize) : taskManagerPointer{ taskManagerPointer }, partitionSize{partitionSize}
{
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}

CFileReader::~CFileReader()
{
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}

void CFileReader::read() {
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CFile inputFile("d:\\in.txt", "rt"); //TODO: set path

	try {
		while (!inputFile.endReached()) {
			std::string inputData = inputFile.read(this->partitionSize);
			this->taskManagerPointer->addInputData(inputData);
		}
	}
	catch (CFileSafeException &readexcept) {
		//TODO: push it to exceptionlist, stop program
	}

	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}