#pragma once

#include "utils.h"
#include "Expr.h"

class ActionBase
{
public:
	virtual string getC()=0;
	
	enum MergeStatus
	{
		SUCCESS,
		FAILURE,
		BLOCKED, 
	};
	
	//virtual MergeStatus attemptMerge(shared_ptr<ActionBase> in) {return FAILURE;};
	
	virtual bool isActionAdd() {return false;}
};

typedef shared_ptr<ActionBase> Action;

Action makeActionAdd(int pos, Expr val);
//Action makeActionShift(int val);
Action makeActionOut(int pos);

class LoopBlockBase;
Action makeActionLoop(shared_ptr<LoopBlockBase> loop, int offset);

