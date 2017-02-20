#include "../h/Expr.h"

int varNameCounter=0;

Variable makeVariable()
{
	string varName = "";
	int i = varNameCounter;
	while (i)
	{
		varName = (char)(i % 26) + varName;
		i/=26;
	}
	varNameCounter++;
	return Variable(new VariableBase(varName));
}

class ExprLiteral: public ExprBase
{
public:
	string getC()
	{
		return to_string(val);
	}
	
	bool isLiteral() {return true;}
	
	int val;
};

Expr makeExprLiteral(int val)
{
	auto out = new ExprLiteral;
	out->val = val;
	return Expr(out);
}



class ExprVariable: public ExprBase
{
public:
	string getC()
	{
		return val->getName();
	}
	
	Variable val;
};

Expr makeExprVariable(Variable val)
{
	auto out = new ExprVariable;
	out->val = val;
	return Expr(out);
}

class ExprSum: public ExprBase
{
public:
	string getC()
	{
		return "(" + a->getC() + " + " + b->getC() + ")";
	}
	
	Expr a, b;
};

Expr makeExprSum(Expr a, Expr b)
{
	if (a->isLiteral() && b->isLiteral())
	{
		return makeExprLiteral(
			((ExprLiteral*)&(*a))->val
			+
			((ExprLiteral*)&(*b))->val
		);
	}
	else
	{
		auto out = new ExprSum;
		out->a = move(a);
		out->b = move(b);
		return Expr(out);
	}
}
