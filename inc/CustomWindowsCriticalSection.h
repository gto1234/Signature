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
	//Restrict acquiring resource in unknown state
	CCustomWindowsCriticalSection(const CCustomWindowsCriticalSection& cs) = delete;
	CCustomWindowsCriticalSection& operator=(const CCustomWindowsCriticalSection& cs) = delete;


	CRITICAL_SECTION windowsCriticalSection;
};