#pragma once
#include <string>
class IWriter {
public:
	virtual ~IWriter() {};

	//Method that will read (thread entrypoint?)
	virtual void write() = 0;
};