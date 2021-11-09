#pragma once
#include <memory>
#include <unordered_map>
#include <stdexcept>

#include "ApplicationSettings.h"

class CCommandLineProcessor
{
public:
	CCommandLineProcessor();
	
	static void showInfoUsage();

	std::shared_ptr<CApplicationSettings> parse(int argumentsCount, char* arguments[]);
private:

};

class CCommadLineArgumentsAnalyzeException
	: public std::runtime_error
{
public:
	CCommadLineArgumentsAnalyzeException(const std::string& error)
		: runtime_error{ error } {}
};