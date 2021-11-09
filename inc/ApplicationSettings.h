#pragma once
#include<string>

class CApplicationSettings
{
public:
	CApplicationSettings();

	void setInputFileName(const std::string& fileName);
	void setOutputFileName(const std::string& fileName);
	void setBlockSize(const size_t blockSize);

	std::string getInputFileName();
	std::string getOutputFileName();
	size_t getBlockSize();

private:
	std::string inputFileName;
	std::string outputFileName;
	size_t blockSize;
};
