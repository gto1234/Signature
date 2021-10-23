#pragma once
#include <memory>

#include "TaskManager.h"

class IReader {
public:		
	virtual ~IReader() {};

	//Set pointer to something that will receive data
	virtual void initialize() = 0; 

	//Method that will read (thread entrypoint?)
	virtual void read() = 0;


};
