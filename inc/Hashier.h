#pragma once
#include <string>
#include <vector>

/*
* Hashire interface. Program used md5 hashier but for ither enougth implement and construct other implementation
*/
class IHashier 
{
public:
	virtual ~IHashier() {}

	/*calculate hash from put data block*/
	virtual std::string calculate(const std::vector<uint8_t>& incomingBuffer) = 0;
};
