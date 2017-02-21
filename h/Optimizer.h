#pragma once

#include "utils.h"
#include "LoopBlock.h"

const int DATA_SIZE=600000;

class Optimizer
{
public:
	Optimizer();
	void add(char c);
	string getC();
	
private:
	vector<LoopBlock> stack{makeLoopBlock()};
};
