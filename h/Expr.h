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

Variable makeVariable();

class ExprBase
{
public:
	virtual string getC()=0;
	virtual bool isLiteral() {return false;}
};

typedef unique_ptr<ExprBase> Expr;

Expr makeExprLiteral(int val);
Expr makeExprVariable(Variable val);
Expr makeExprSum(Expr a, Expr b);
