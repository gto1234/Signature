#pragma once
#include<string>

/*
* Application settings data transfer object
*/
class CApplicationSettings
{
public:
	CApplicationSettings();

	/*Set input file name*/
	void setInputFileName(const std::string& fileName);

	/*Set output file name*/
	void setOutputFileName(const std::string& fileName);

	/*Set size of reading block*/
	void setBlockSize(const size_t blockSize);

	/*get input file name*/
	std::string getInputFileName();

	/*get output file name*/
	std::string getOutputFileName();

	/*get size of reading block*/
	size_t getBlockSize();

private:
	std::string inputFileName;
	std::string outputFileName;
	size_t blockSize;
};
