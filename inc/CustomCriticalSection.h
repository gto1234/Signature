#pragma once

/*
* Custom critical section. With pair of CustomerLocker make RAII-style critical section object
*/
class ICustomCriticalSection
{
public:	
	virtual ~ICustomCriticalSection() {};

	virtual void lock() = 0;

	virtual void unlock() = 0;
};