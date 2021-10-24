#include <stdint.h>
#include <vector>

#include "File.h"
#include "DebugLogger.h"


CFile::CFile(const std::string& filePath, const std::string& accessMode) : filePointer(nullptr)
{
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	fopen_s(&this->filePointer, filePath.c_str(), accessMode.c_str());

	if (this->filePointer == nullptr)
	{
		throw CFileSafeException("Could not open file");
	}
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}
CFile::~CFile()
{
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	if (this->filePointer != nullptr)
		fclose(this->filePointer);
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
}

std::string CFile::read(size_t bytesSize)
{
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
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

	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
	return outBuffer;
}

bool CFile::endReached()
{
	CDebugLogger::log("Called " + std::string(__FUNCSIG__));
	CDebugLogger::log("Leaved " + std::string(__FUNCSIG__));
	return feof(this->filePointer);
}
