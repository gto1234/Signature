#include "FileWriter.h"
#include "DebugLogger.h"
#include "File.h"
#include "ExceptionStorage.h"

CFileWriter::CFileWriter(std::shared_ptr<ITaskManager> taskManagerPointer, const std::string& fileName) :
	taskManagerPointer {taskManagerPointer},
	fileName { fileName }
{
}

CFileWriter::~CFileWriter()
{
}

void CFileWriter::write()
{
	try
	{
		CFile outputFile(this->fileName, CFile::EOpenMode::WRITE);

		do
		{
			std::shared_ptr<CTaskNode> taskNode = this->taskManagerPointer->getForWrite();

			if (taskNode == nullptr)
			{
			}
			else
			{
				outputFile.write(taskNode->getHash());
				taskNode->reset(); //It is unnecessary for Parallel implementation but necessary for NonParallel. Count as requirment for call to work; Still alive just for compatibility
			}
		} 
		while (this->taskManagerPointer->isApplicationActive());
	}
	catch (CFileSafeException& fileOpenExcept) //opening file error
	{
		this->taskManagerPointer->forceStop(); //We can put here forcestop
		CExceptionStorage::getInstance().push(fileOpenExcept);
	}
	catch (std::exception& commonException) //All other exceptions
	{
		this->taskManagerPointer->forceStop();
		CExceptionStorage::getInstance().push(commonException);		
	}
}
