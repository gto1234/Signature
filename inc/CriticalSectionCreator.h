#pragma once
#include <memory>

#include "CustomCriticalSection.h"

/*
* generates custom critical section
*/
class CCriticalSectionCreator
{
public:
	static std::shared_ptr<ICustomCriticalSection> create();
};