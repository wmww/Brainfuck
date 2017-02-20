#pragma once

#include "utils.h"
#include "Action.h"

class LoopBlock
{
public:
	LoopBlock(Expr pos);
	void mergeInto(LoopBlock& in);
	void add(char c);
	void add(Action a);
	string getC();
	
	Expr pos;
	vector<Action> actions;
};
