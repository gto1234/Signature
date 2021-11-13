#include <iostream>

#include "FileReader.h"
#include "File.h"
#include "DebugLogger.h"
#include "ExceptionStorage.h"

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
	try 
	{
		CFile inputFile(this->fileName, CFile::EOpenMode::READ);

		while (!inputFile.endReached()) {
			try {
				std::vector<uint8_t> inputData = inputFile.read(this->partitionSize); //Read partition by partition
				this->taskManagerPointer->addInputData(inputData); //add it to processing
			}
			catch (CFileReadEndOnBorder& e)
			{
				//feof will not raised if last byte that read was last in partition, so it exception hadlong restrict adding zero-filled partition
				break;
			}
			
		}
		this->taskManagerPointer->indicateReadingFinished();
	}
	catch (CFileSafeException& fileOpenExcept) //opening file error or reading error
	{
		this->taskManagerPointer->indicateReadingFinished(); //We can put here forcestop but 
		CExceptionStorage::getInstance().push(fileOpenExcept);
	}
	catch (std::exception& commonException) //All other exceptions
	{
		CExceptionStorage::getInstance().push(commonException);
		this->taskManagerPointer->forceStop();
	}
}