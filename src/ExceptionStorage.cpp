#include <iostream>

#include "ExceptionStorage.h"

CExceptionStorage& CExceptionStorage::getInstance()
{
	static CExceptionStorage instance;
	return instance;	
}

CExceptionStorage::CExceptionStorage()
{
	this->exceptionListCriticalSection = CCriticalSectionCreator::create();
}

void CExceptionStorage::push(std::exception& error)
{
	CCustomLocker exceptionListLocker(this->exceptionListCriticalSection);
	this->exceptionList.emplace_back(error);	
}

void CExceptionStorage::printAll()
{
	int index = 1;
	if (!this->exceptionList.empty())
	{
		std::cout << "Program finished with error(s). Result might be not correct" << std::endl;
	}

	for (auto it : this->exceptionList)
	{
		std::cout << "Error " << index << ": " << it.what() << std::endl;
		index++;
	}
}
