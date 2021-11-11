#pragma once

class ICustomCriticalSection
{
public:	
	virtual ~ICustomCriticalSection() {};

	virtual void lock() = 0;
	virtual void unlock() = 0;
};