#pragma once
#include <string>
class IWriter {
public:
	virtual ~IWriter() {};

	//Set pointer to something that will receive data
	virtual void initialize() = 0;

	//Method that will read (thread entrypoint?)
	virtual void write(const std::string& calculatedHashValue) = 0;
};