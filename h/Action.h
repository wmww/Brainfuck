#pragma once

#include "utils.h"
#include "Expr.h"

#include <map>

enum SubActionType
{
	ACTION_ADD,
	ACTION_SET,
	ACTION_OUT,
	ACTION_IN,
};

class ActionBase
{
public:
	
	virtual shared_ptr<ActionBase> makeCopy()=0;
	
	virtual string getC()=0;
	//virtual string getCUnrolled() {return "// error: can not unroll this type of action\n";};
	
	virtual bool isMapAdd() {return false;}
	
	virtual bool canUnroll() {return false;}
	
	virtual void unroll(int offset) {cout << "called unroll on an action that can't be unrolled" << endl;};
	
	virtual Expr getNetChangeToPos(int i) {return exprIdk();};
	
	// if this is not a map add action, all these will not work
	virtual void addSubAction(int pos, SubActionType type, Expr expr)
	{
		cout << "addSubAction() called on action other then add map" << endl;
	}
	//virtual bool onlyHasAddSubs() {return false;}
	//virtual std::map<int, vector<SubAction> >* getData() {return nullptr;}
};

typedef shared_ptr<ActionBase> Action;

//Action makeActionAdd(int pos, Expr val);
//Action makeActionShift(int val);
//Action makeActionOut(int pos);

Action makeActionMapAdd();

class LoopBlockBase;

Action makeActionLoop(shared_ptr<LoopBlockBase> loop, int offset);
