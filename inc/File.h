#pragma once
#include <string>
#include <stdexcept>

#include <vector>

/*
* Represents RAII-wrapper for file
*/
class CFile
{	
public:
	enum class  EOpenMode
	{
		READ,
		WRITE,
	};

	CFile(const std::string& path, const EOpenMode mode);
	~CFile();

	//Restrict acquiring resource with unknown state
	CFile(const CFile& f) = delete;
	CFile& operator=(const CFile& f) = delete;

	/*Read block from file*/
	std::vector<uint8_t> read(size_t bytesSize);

	/*Write string to file*/
	void write(const std::string& outString);

	/*Check that end of file reached*/
	bool endReached();
private:
	FILE* filePointer;
	std::string fileName;
	EOpenMode openedMode;
};

/*
* Represents I/O error
*/
class CFileSafeException : public std::runtime_error
{
public:
	CFileSafeException(const std::string& error) : runtime_error(error) {}
};

/*
* Not erorr but serve to throw exit and stop reading in case when last byte read is last byte of partition (in this case EOF flag will not rised)
*/
class CFileReadEndOnBorder : public std::runtime_error
{
public:
	CFileReadEndOnBorder(const std::string& error) : runtime_error(error) {}
};