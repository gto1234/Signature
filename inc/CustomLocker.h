#pragma once
#include<memory>

#include "CustomCriticalSection.h"

/*
* RAII-wrapper for critical sections. Enougth to create its instance - thread become locked. When instance removed then thread become unlocked
*/
class CCustomLocker
{
public:
	CCustomLocker() = delete;

	/*Lock received critical section*/
	CCustomLocker(std::shared_ptr<ICustomCriticalSection>);

	/*On this release wrapped critical section*/
	virtual ~CCustomLocker();
private:
	std::shared_ptr<ICustomCriticalSection> controlledCriticalSection;
};
