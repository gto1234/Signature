#pragma once
#include <string>
#include <memory>
#include <vector>

#include "Md5Hashier.h"

/*
* Processing data block object
*/
class CTaskNode 
{
public:
	//For non parallel we have one object for all application time life
	CTaskNode();

	//For parallel we have separate object for each block
	CTaskNode(const std::vector<uint8_t>& inputData);

	~CTaskNode();

	enum class EState 
	{
		ON_IDLE,
		NEW_VALUE,
		HASH_CALCULATED,
	};

	//Set new data, switch it to NEW_VALUE
	void setInputData(const std::vector<uint8_t>& inputData);

	//calculates hash
	void calculate();

	//Get hash value
	std::string getHash();

	//Switch to IDLE - ready to work next
	void reset();

	//return current state
	EState getState();
private:
	std::vector<uint8_t> inputData;
	std::string hash;
	EState taskNodeState;
	std::shared_ptr<IHashier> hasier;
};
