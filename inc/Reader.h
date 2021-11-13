#pragma once
#include <memory>

#include "TaskManager.h"

/*
* interface represends reading incoming data
*/
class IReader 
{
public:		
	virtual ~IReader() {};

	/*Thread entrypoint method*/
	virtual void read() = 0;
};
