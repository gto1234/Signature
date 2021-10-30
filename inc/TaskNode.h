#pragma once
#include <string>
#include <memory>

#include "Md5Hashier.h"

class CTaskNode {
public:
	CTaskNode();
	CTaskNode(const std::string& inputData);
	~CTaskNode();

	enum class EState {
		ON_IDLE,
		NEW_VALUE,
		TAKEN_BY_HASHIER, //will used in multithread
		HASH_CALCULATED,
	};

	//Set new data, switch it to NEW_VALUE
	void setInputData(const std::string& inputData);

	//calculates hash
	void calculate();

	//Get hash value
	std::string getHash();

	//Switch to IDLE - ready to work next
	void reset();

	//return current state
	EState getState();
private:
	std::string inputData;
	std::string hash;
	EState taskNodeState;
	std::shared_ptr<IHashier> hasier; //TODO: hashier is the same for all... move it to global
};
