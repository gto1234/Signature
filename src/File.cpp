#include <iostream>
#include <stdint.h>

#include "File.h"
#include "DebugLogger.h"


CFile::CFile(const std::string& filePath, const EOpenMode mode) : 
	filePointer{ nullptr },
	fileName{ filePath },
	openedMode{ mode }
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
		throw CFileSafeException("Could not open file " + filePath);
	}
}
CFile::~CFile()
{
	if (this->filePointer != nullptr) {
		fclose(this->filePointer);
	}	
}

std::vector<uint8_t> CFile::read(size_t bytesSize)
{
	const uint8_t countReadValues = 1;
	std::string outBuffer = "";
	std::vector<uint8_t> readbuffer(bytesSize);

	if (this->openedMode != EOpenMode::READ)
		throw CFileSafeException("File " + this->fileName + " not opened for read");

	size_t actualRead = fread(readbuffer.data(), bytesSize, countReadValues, this->filePointer);
	if (actualRead < countReadValues) {
		if (!feof(this->filePointer)) {
			throw CFileSafeException("File " + this->fileName + " read error");
		}
		else {
			if (actualRead == 0) {
				throw CFileReadEndOnBorder("");
			}

			for (unsigned int i = 0; i < countReadValues - actualRead; i++) {
				readbuffer[actualRead + i] = 0;
			}
		}
	}

	return readbuffer;
}

void CFile::write(const std::string& outString) 
{
	if (this->openedMode != EOpenMode::WRITE)
		throw CFileSafeException("File " + this->fileName + " not opened for write");

	int ret = fputs(outString.c_str(), this->filePointer);
	if (ret == EOF)
	{
		throw CFileSafeException("File " + this->fileName + " write error");
	}
}

bool CFile::endReached()
{
	return feof(this->filePointer);
}
