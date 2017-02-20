#pragma once

#include "utils.h"
#include "LoopBlock.h"

class Optimizer
{
public:
	Optimizer();
	void add(char c);
	string getC();
	
private:
	vector<LoopBlock> stack{LoopBlock()};
};
