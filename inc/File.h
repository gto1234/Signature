#pragma once
#include <string>
#include <stdexcept>

class CFile
{
public:
	CFile(const std::string& sPath, const std::string& sMode);
	~CFile();

	CFile(const CFile& f) = delete;
	CFile& operator=(const CFile& f) = delete;

	std::string read(size_t bytesSize);
	void write(const std::string& outString);

	bool endReached();
private:
	FILE* filePointer;
};

class CFileSafeException : public std::runtime_error
{
public:
	CFileSafeException(const std::string& error) : runtime_error(error) {}
};