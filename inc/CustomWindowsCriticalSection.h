#pragma once

#include <Windows.h>
#include "CustomCriticalSection.h"

class CCustomWindowsCriticalSection : public ICustomCriticalSection
{
public:
	CCustomWindowsCriticalSection();

	void lock();
	void unlock();
private:
	CRITICAL_SECTION windowsCriticalSection;
};