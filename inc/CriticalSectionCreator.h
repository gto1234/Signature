#pragma once
#include <memory>

#include "CustomCriticalSection.h"

class CCriticalSectionCreator
{
public:
	static std::shared_ptr<ICustomCriticalSection> create();
};