#pragma once
#include "Hashier.h"

class CMd5Hashier : public IHashier {
public:
	CMd5Hashier();
	~CMd5Hashier();

	virtual std::string calculate(const std::string& incomingBuffer);
};