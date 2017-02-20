#pragma once

#include "utils.h"
#include "Action.h"

class LoopBlock
{
public:
	LoopBlock();
	void mergeInto(LoopBlock& in);
	void add(char c);
	
private:
	
	int pos=0;
	vector<Action> actions;
};
