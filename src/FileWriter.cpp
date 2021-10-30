#include "FileWriter.h"
#include "DebugLogger.h"
#include "File.h"

CFileWriter::CFileWriter(std::shared_ptr<ITaskManager> taskManagerPointer) : taskManagerPointer {taskManagerPointer}
{
}

CFileWriter::~CFileWriter()
{
}

void CFileWriter::write()
{
	CFile outputFile("d:\\out.txt", "wt"); //TODO: set path

	do
	{
		std::shared_ptr<CTaskNode> taskNode = this->taskManagerPointer->getForWrite();

		if (taskNode == nullptr) {

		}
		else {			
			outputFile.write(taskNode->getHash()); //TODO: handle exception
			taskNode->reset();
		}
	} while (this->taskManagerPointer->isApplicationActive());
}
