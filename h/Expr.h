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
	virtual bool isIdk() {return false;}
	virtual bool isLiteral() {return false;}
	virtual bool isZero() {return false;}
	virtual bool equals(shared_ptr<ExprBase> other) {return false;}
};

typedef shared_ptr<ExprBase> Expr;

Expr expr();
Expr exprIdk();
Expr expr(int val);
Expr exprFromData(int pos, int * offset);
Expr expr(Variable val);
Expr sum(Expr a, Expr b);
Expr product(Expr a, Expr b);

