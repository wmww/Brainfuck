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
	vector<shared_ptr<ExprBase>> subs;
	
	virtual string getC()=0;
	virtual bool isIdk() {return false;}
	virtual bool isLiteral() {return false;}
	virtual bool isZero() {return false;}
	virtual bool isOne() {return false;}
	virtual int getLiteralVal() {cout << "getLiteralVal() called on a non literal expr" << endl; return 0;}
	virtual bool equals(shared_ptr<ExprBase> other) {return false;}
};

typedef shared_ptr<ExprBase> Expr;

Expr expr();
Expr exprIdk();
Expr expr(int val);
Expr exprFromData(int pos);
Expr expr(Variable val);
Expr sum(Expr a, Expr b);
Expr product(Expr a, Expr b);
Expr quotient(Expr a, Expr b);
Expr negative(Expr a);

