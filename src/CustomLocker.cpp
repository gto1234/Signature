#include "CustomLocker.h"
CCustomLocker::CCustomLocker(std::shared_ptr<ICustomCriticalSection> criticalSection) : controlledCriticalSection{ criticalSection }
{
	controlledCriticalSection->lock();
}

CCustomLocker::~CCustomLocker()
{
	controlledCriticalSection->unlock();
}