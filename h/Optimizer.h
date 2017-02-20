#pragma once

#include "utils.h"

class Action
{
public:
	
	enum Type
	{
		NONE=0,
		ADD,
		SET,
		OUT,
		IN,
	};
	
	//Action(char c);
	//bool mergeWith(Action& other); //tries to merge the actions, returns true if succeeded, false otherwise
	
	Type type=NONE;
	int val=0; // not used for in and out
	int i=0; // reletive index
};

class Block
{
public:
	Block();
	void add(char c);
	
private:
	
	int pos=0;
	vector<Action> actions;
};

class Optimizer
{
public:
	Optimizer();
	void add(char c);
	string getC();
	
private:
	vector<Block> stack;
};
