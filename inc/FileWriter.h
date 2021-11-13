#pragma once
#include <memory>
#include "TaskManager.h"
#include "Writer.h"

/*
* Represents entrypoint-class method of that write outcoming data
*/
class CFileWriter : public IWriter 
{
public:
	CFileWriter(std::shared_ptr<ITaskManager> taskManagerPointer, const std::string& fileName);

	~CFileWriter();

	/*Thread entrypoint method*/
	void write();
private:
	std::shared_ptr<ITaskManager> taskManagerPointer;
	std::string fileName;
};