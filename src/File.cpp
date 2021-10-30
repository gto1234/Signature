#include <stdint.h>
#include <vector>

#include "File.h"
#include "DebugLogger.h"


CFile::CFile(const std::string& filePath, const std::string& accessMode) : filePointer(nullptr)
{
	//TODO: rework mode R/W
	fopen_s(&this->filePointer, filePath.c_str(), accessMode.c_str());

	if (this->filePointer == nullptr)
	{
		throw CFileSafeException("Could not open file");
	}
}
CFile::~CFile()
{
	if (this->filePointer != nullptr)
		fclose(this->filePointer);
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
				readbuffer[actualRead + i] = ' ';
			}
		}
	}

	//TODO: not optimized - rework to single buffer
	for (unsigned int i = 0; i < bytesSize; i++)
		outBuffer += readbuffer[i];

	return outBuffer;
}

void CFile::write(const std::string& outString) {
	//TODO: check for all IO exceptions
	fputs(outString.c_str(), this->filePointer);
}

bool CFile::endReached()
{
	return feof(this->filePointer);
}
