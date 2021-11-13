#pragma once
#include <memory>

#include "Reader.h"
#include "TaskManager.h"

/*
* Represents entrypoint-class method of that read incoming data
*/
class CFileReader : public  IReader 
{
public:
	CFileReader(std::shared_ptr<ITaskManager> taskManagerPointer, const std::string& fileName, unsigned long int partitionSize);

	~CFileReader();

	/*Thread entrypoint method*/
	void read();
private:
	std::shared_ptr<ITaskManager> taskManagerPointer;
	unsigned long int partitionSize;
	std::string fileName;
};