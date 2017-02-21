#pragma once

#include "utils.h"
#include "Expr.h"

enum SubActionType
{
	ACTION_ADD,
	ACTION_OUT,
	ACTION_IN,
};

class ActionBase
{
public:
	virtual string getC()=0;
	
	// if this is not a map add action, this will error
	virtual void addSubAction(int pos, SubActionType type, Expr expr)
	{
		cout << "addSubAction() called on action other then add map" << endl;
	}
	
	virtual bool isMapAdd() {return false;}
};

typedef shared_ptr<ActionBase> Action;

//Action makeActionAdd(int pos, Expr val);
//Action makeActionShift(int val);
//Action makeActionOut(int pos);

Action makeActionMapAdd();

class LoopBlockBase;
Action makeActionLoop(shared_ptr<LoopBlockBase> loop, int offset);

