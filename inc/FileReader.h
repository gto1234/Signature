#pragma once
#include <memory>

#include "Reader.h"
#include "TaskManager.h"

class CFileReader : public  IReader {
public:
	CFileReader(std::shared_ptr<ITaskManager> taskManagerPointer, unsigned long int partitionSize);
	~CFileReader();

	//Method that will read (thread entrypoint?)
	virtual void read();
private:
	std::shared_ptr<ITaskManager> taskManagerPointer;
	unsigned long int partitionSize;
};