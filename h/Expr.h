#pragma once

#include "utils.h"

class VariableBase
{
public:
	VariableBase(string in) {name=in;}
	string getName() {return name;}
	
private:
	string name;
};

typedef shared_ptr<VariableBase> Variable;

Variable newVariable();

class ExprBase
{
public:
	virtual string getC()=0;
};

typedef unique_ptr<ExprBase> Expr;

Expr newExprLiteral(int val);
