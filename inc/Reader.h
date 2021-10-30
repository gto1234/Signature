#pragma once
#include <memory>

#include "TaskManager.h"

class IReader 
{
public:		
	virtual ~IReader() {};

	//Method that will read (thread entrypoint?)
	virtual void read() = 0;
};
