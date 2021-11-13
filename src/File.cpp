#include <iostream>
#include <stdint.h>
#include <vector>

#include "File.h"
#include "DebugLogger.h"


CFile::CFile(const std::string& filePath, const EOpenMode mode) : filePointer(nullptr)
{
	switch (mode)
	{
	case EOpenMode::READ:
		fopen_s(&this->filePointer, filePath.c_str(), "rb");
		break;
	case EOpenMode::WRITE:
		fopen_s(&this->filePointer, filePath.c_str(), "wt");
		break;
	default:
		throw CFileSafeException("Unknown opening mode");
	}

	if (this->filePointer == nullptr)
	{
		throw CFileSafeException("Could not open file");
	}
}
CFile::~CFile()
{
	if (this->filePointer != nullptr) {
		int ret = fclose(this->filePointer);
		if (ret == EOF)
		{
			throw new CFileSafeException("File closing error");
		}
	}
}

std::string CFile::read(size_t bytesSize)
{
	const uint8_t countReadValues = 1;
	std::string outBuffer = "";
	std::vector<uint8_t> readbuffer(bytesSize);

	size_t actualRead = fread(readbuffer.data(), bytesSize, countReadValues, this->filePointer);
	if (actualRead < countReadValues) {
		if (!feof(this->filePointer)) {
			throw new CFileSafeException("File read error");
		}
		else {			
			for (unsigned int i = 0; i < countReadValues - actualRead; i++) {
				readbuffer[actualRead + i] = 0;
			}
		}
	}

	for (unsigned int i = 0; i < bytesSize; i++)
		outBuffer += readbuffer[i];

	return outBuffer;
}

void CFile::write(const std::string& outString) 
{
	int ret = fputs(outString.c_str(), this->filePointer);
	if (ret == EOF)
	{
		throw new CFileSafeException("File write error");
	}
}

bool CFile::endReached()
{
	return feof(this->filePointer);
}
