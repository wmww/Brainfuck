#pragma once

#include "utils.h"
#include "Block.h"
#include "Loop.h"

const int DATA_SIZE=600000;

class Optimizer
{
public:
	Optimizer();
	void add(char c);
	string getC();
	
private:
	Block rootBlock;
	Block* currentBlock;
};
