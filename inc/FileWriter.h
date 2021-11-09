#pragma once
#include <memory>
#include "TaskManager.h"
#include "Writer.h"

class CFileWriter : public IWriter 
{
public:
	CFileWriter(std::shared_ptr<ITaskManager> taskManagerPointer, const std::string& fileName);
	~CFileWriter();

	//Method that will read (thread entrypoint?)
	void write();
private:
	std::shared_ptr<ITaskManager> taskManagerPointer;
	std::string fileName;
};