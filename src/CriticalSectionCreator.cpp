#include "CriticalSectionCreator.h"

#include "CustomWindowsCriticalSection.h"

std::shared_ptr<ICustomCriticalSection> CCriticalSectionCreator::create()
{
	//TODO: For support linux or other from Windows OS should be implemented routine for create different implementations of "CustomCriticalSection interface"
	return std::make_shared<CCustomWindowsCriticalSection>();
}