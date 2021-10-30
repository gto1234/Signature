#include <iostream>

#include "TaskNode.h"
#include "DebugLogger.h"
CTaskNode::CTaskNode() : inputData{ "" }, hash{ "" }, taskNodeState{ EState::ON_IDLE }
{
	this->hasier = std::make_shared<CMd5Hashier>();
}
CTaskNode::CTaskNode(const std::string& inputData) : inputData{ inputData }, hash{ "" }, taskNodeState{ EState::NEW_VALUE }
{

}
CTaskNode::~CTaskNode() 
{

}


void CTaskNode::setInputData(const std::string& inputData) 
{
	this->inputData = inputData;
	this->taskNodeState = EState::NEW_VALUE;
}


void CTaskNode::calculate() 
{
	this->hash = this->hasier->calculate(this->inputData);
	this->taskNodeState = EState::HASH_CALCULATED;
}


std::string CTaskNode::getHash() 
{
	return this->hash;
}


void CTaskNode::reset() 
{
	this->taskNodeState = EState::ON_IDLE;
}

CTaskNode::EState CTaskNode::getState() 
{
	return this->taskNodeState;
}