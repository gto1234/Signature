#pragma once
#include <string>

class IHashier {
public:
	virtual ~IHashier() {}

	virtual std::string calculate(const std::string& incomingBuffer) = 0;
};
