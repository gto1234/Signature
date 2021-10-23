#pragma once
#include "Hashier.h"

class CMd5Hashier : public IHashier {
public:
	virtual std::string calculate(const std::string& incomingBuffer);
};