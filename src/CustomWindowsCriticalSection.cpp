#include "CustomWindowsCriticalSection.h"

CCustomWindowsCriticalSection::CCustomWindowsCriticalSection()
{
	InitializeCriticalSection(&this->windowsCriticalSection);
}

void CCustomWindowsCriticalSection::lock()
{
	EnterCriticalSection(&this->windowsCriticalSection);
}
void CCustomWindowsCriticalSection::unlock()
{
	LeaveCriticalSection(&this->windowsCriticalSection);
}
