#include "ApplicationSettings.h"

CApplicationSettings::CApplicationSettings() :
	blockSize {1024 * 1024}, //1Mb by default
	inputFileName{""},
	outputFileName{""}
{
}

void CApplicationSettings::setInputFileName(const std::string& fileName)
{
	this->inputFileName = fileName;
}

void CApplicationSettings::setOutputFileName(const std::string& fileName)
{
	this->outputFileName = fileName;
}

void CApplicationSettings::setBlockSize(const size_t blockSize)
{
	this->blockSize = blockSize;
}

std::string CApplicationSettings::getInputFileName()
{
	return this->inputFileName;
}

std::string CApplicationSettings::getOutputFileName()
{
	return this->outputFileName;
}

size_t CApplicationSettings::getBlockSize()
{
	return this->blockSize;
}
