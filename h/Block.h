#pragma once

#include "utils.h"
#include "Expr.h"
#include "Action.h"
#include <map>

/*
#include <map>

enum SubActionType
{
	ACTION_ADD,
	ACTION_SET,
	ACTION_OUT,
	ACTION_IN,
};
*/

class LoopBase;

class Block
{
public:
	
	struct CellChange
	{
		bool absoluteSet; // if false then val is added to what is already in the cell
		Expr val;
		
		Expr getExpr(int pos);
	};
	
	void appendAction(char c);
	
	string getC();
	
	void addAction(Action action);
	
	CellChange& getCell(int index);
	
	void addToCell(int index, Expr val);
	
	int pos = 0;
	std::map<int, CellChange> cells;
	vector<Action> actions;
	bool isRoot = false;
	shared_ptr<LoopBase> parentLoop = nullptr;
	shared_ptr<LoopBase> nextLoop = nullptr;
	
	//virtual shared_ptr<ActionBase> makeCopy()=0;
	//virtual string getCUnrolled() {return "// error: can not unroll this type of action\n";};
	//virtual bool isMapAdd() {return false;}
	//virtual bool canUnroll() {return false;}
	//virtual void unroll(int offset) {cout << "called unroll on an action that can't be unrolled" << endl;};
	//virtual Expr getNetChangeToPos(int i) {return exprIdk();};
	
	// if this is not a map add action, all these will not work
	//virtual bool onlyHasAddSubs() {return false;}
	//virtual std::map<int, vector<SubAction> >* getData() {return nullptr;}
};
