#pragma once

#include "utils.h"
#include "Action.h"

class LoopBlockBase
{
public:
	LoopBlockBase();
	void mergeFrom(shared_ptr<LoopBlockBase> src);
	void add(char c);
	void add(Action a);
	void addToCell(SubActionType type, Expr val);
	void zeroPos();
	void shiftPos(int dist);
	string getC();
	
	int pos;
	//int totalOffset;
	vector<Action> actions;
};

typedef shared_ptr<LoopBlockBase> LoopBlock;

LoopBlock makeLoopBlock();
