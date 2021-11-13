#pragma once
#include <list>
#include <stdexcept>
#include <memory>

#include "CustomCriticalSection.h"
#include "CustomLocker.h"
#include "CriticalSectionCreator.h"

/*
* Represents list of collected exceptions during execution if some error(s) occured (except exceptions occured before start ProcessManager (they are processed directly))
*/
class CExceptionStorage
{
public:
	static CExceptionStorage& getInstance();

	/*add exception to list*/
	void push(std::exception& error);

	/*print all collected exceptions*/
	void printAll();

private:
	CExceptionStorage();
	
	//Restrict singleton copying
	CExceptionStorage(const CExceptionStorage&) = delete;
	CExceptionStorage& operator=(CExceptionStorage&) = delete;

	std::list<std::exception> exceptionList;
	std::shared_ptr<ICustomCriticalSection> exceptionListCriticalSection;
};
