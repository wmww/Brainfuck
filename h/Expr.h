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

typedef shared_ptr<ExprBase> Expr;

Expr expr(int val);
Expr expr(Variable val);
Expr sum(Expr a, Expr b);
