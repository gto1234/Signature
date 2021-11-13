#pragma once
#include <memory>
#include <stdexcept>

#include "ApplicationSettings.h"

/*
* Class respond for command line parameter parsing and generating application settings data transfer object
*/
class CCommandLineProcessor
{
public:
	CCommandLineProcessor();
	
	/*Show command line parameters call specification*/
	static void showInfoUsage();

	/*parse command line and create application settings DTO*/
	std::shared_ptr<CApplicationSettings> parse(int argumentsCount, char* arguments[]);
};

/*Internal exception appears when command line arguments are incorrect (format or count of them)*/
class CCommadLineArgumentsAnalyzeException
	: public std::runtime_error
{
public:
	CCommadLineArgumentsAnalyzeException(const std::string& error)
		: runtime_error{ error } {}
};