#pragma once
#include<memory>

#include "CustomCriticalSection.h"

class CCustomLocker
{
public:
	CCustomLocker() = delete;
	CCustomLocker(std::shared_ptr<ICustomCriticalSection>);
	virtual ~CCustomLocker();
private:
	std::shared_ptr<ICustomCriticalSection> controlledCriticalSection;
};
