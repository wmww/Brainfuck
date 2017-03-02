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
	
	bool isZero() {return val==0;}
	
	bool isOne() {return val==1;}
	
	int getLiteralVal() {return val;}
	
	bool equals(Expr other)
	{
		return (other->isLiteral() && (((ExprLiteral*)&(*other))->val == val));
	}
	
	int val;
};

Expr expr(int val)
{
	auto out = new ExprLiteral;
	out->val = val;
	return Expr(out);
}

Expr expr()
{
	return expr(0);
}



class ExprFromData: public ExprBase
{
public:
	string getC()
	{
		return "p[" + to_string(pos) + "]";
	}
	
	int pos;
};

Expr exprFromData(int pos)
{
	auto out = new ExprFromData;
	out->pos = pos;
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

Expr expr(Variable val)
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
		return "(" + subs[0]->getC() + " + " + subs[1]->getC() + ")";
	}
};

Expr sum(Expr a, Expr b)
{
	if (a->isIdk() || b->isIdk())
	{
		return exprIdk();
	}
	else if (a->isLiteral() && b->isLiteral())
	{
		return expr(
			((ExprLiteral*)&(*a))->val
			+
			((ExprLiteral*)&(*b))->val
		);
	}
	else if (a->isZero())
	{
		return b;
	}
	else if (b->isZero())
	{
		return a;
	}
	else
	{
		auto out = new ExprSum;
		out->subs.push_back(move(a));
		out->subs.push_back(move(b));
		return Expr(out);
	}
}


class ExprProduct: public ExprBase
{
public:
	string getC()
	{
		return "(" + subs[0]->getC() + " * " + subs[1]->getC() + ")";
	}
};

Expr product(Expr a, Expr b)
{
	if (a->isIdk() || b->isIdk())
	{
		return exprIdk();
	}
	else if (a->isLiteral() && b->isLiteral())
	{
		return expr(
			a->getLiteralVal()
			*
			b->getLiteralVal()
		);
	}
	else if (a->isLiteral() && a->getLiteralVal() == -1)
	{
		return negative(b);
	}
	else if (b->isLiteral() && b->getLiteralVal() == -1)
	{
		return negative(a);
	}
	else if (a->isOne())
	{
		return b;
	}
	else if (b->isOne())
	{
		return a;
	}
	else
	{
		auto out = new ExprProduct;
		out->subs.push_back(move(a));
		out->subs.push_back(move(b));
		return Expr(out);
	}
}


class ExprQuotient: public ExprBase
{
public:
	string getC()
	{
		return "(" + subs[0]->getC() + " / " + subs[1]->getC() + ")";
	}
};

Expr quotient(Expr a, Expr b)
{
	if (a->isIdk() || b->isIdk())
	{
		return exprIdk();
	}
	else if (b->isZero())
	{
		return exprIdk();
	}
	else if (b->isOne())
	{
		return a;
	}
	else if (b->isLiteral() && ((ExprLiteral*)&(*b))->val == -1)
	{
		return negative(a);
	}
	else if (a->isLiteral() && b->isLiteral())
	{
		return expr(
			a->getLiteralVal()
			/
			b->getLiteralVal()
		);
	}
	else
	{
		auto out = new ExprQuotient;
		out->subs.push_back(move(a));
		out->subs.push_back(move(b));
		return Expr(out);
	}
}


class ExprNegative: public ExprBase
{
public:
	string getC()
	{
		return "(-" + subs[0]->getC() + ")";
	}
};

Expr negative(Expr a)
{
	if (a->isIdk())
	{
		return exprIdk();
	}
	else if (a->isLiteral())
	{
		return expr(-a->getLiteralVal());
	}
	else
	{
		auto out = new ExprNegative;
		out->subs.push_back(move(a));
		return Expr(out);
	}
}




class ExprIdk: public ExprBase
{
public:
	string getC()
	{
		return "\n#error ExprIdk made it into the transpiled C source\n";
	}
	
	bool isIdk() {return true;}
};

Expr exprIdk()
{
	auto out = new ExprIdk;
	return Expr(out);
}


