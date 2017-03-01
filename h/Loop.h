#pragma once

#include "utils.h"
#include "Block.h"

class LoopBase: public enable_shared_from_this<LoopBase>
{
public:
	LoopBase();
	string getC();
	
	Block contentsBlock;
	Block nextBlock;
	Block prevBlock;
};

typedef shared_ptr<LoopBase> Loop;

Loop makeLoop(Block prevBlock);

/*
class LoopBlockBase
{
public:
	LoopBlockBase();
	shared_ptr<LoopBlockBase> makeCopy();
	void mergeFrom(shared_ptr<LoopBlockBase> src);
	void shiftPos(int dist);
	void add(char c);
	void addToCell(SubActionType type, int pos, Expr val);
	Expr getNetChangeToPos(int i);
	//void zeroPos();
	bool canUnroll();
	void unroll(int offset);
	string getC();
	
	int pos;
	//int totalOffset;
	vector<Action> actions;
};

typedef shared_ptr<LoopBlockBase> LoopBlock;

LoopBlock makeLoopBlock();
*/

