#pragma once
#include <string>

/*
* interface represends reading outcoming data
*/
class IWriter 
{
public:
	virtual ~IWriter() {};

	/*Thread entrypoint method*/
	virtual void write() = 0;
};