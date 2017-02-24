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
		return "_p[" + to_string(pos + *offset) + "]";
	}
	
	int pos;
	int * offset; //this will point to the offset int in the ActionMapAdd this Expr is in
};

Expr exprFromData(int pos, int * offset)
{
	auto out = new ExprFromData;
	out->pos = pos;
	out->offset = offset;
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
		return "(" + a->getC() + " + " + b->getC() + ")";
	}
	
	Expr a, b;
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
		out->a = move(a);
		out->b = move(b);
		return Expr(out);
	}
}


class ExprProduct: public ExprBase
{
public:
	string getC()
	{
		return "(" + a->getC() + " * " + b->getC() + ")";
	}
	
	Expr a, b;
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
			((ExprLiteral*)&(*a))->val
			*
			((ExprLiteral*)&(*b))->val
		);
	}
	else if (a->isLiteral() && ((ExprLiteral*)&(*a))->val == -1)
	{
		return negative(b);
	}
	else if (b->isLiteral() && ((ExprLiteral*)&(*b))->val == -1)
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
		out->a = move(a);
		out->b = move(b);
		return Expr(out);
	}
}


class ExprQuotient: public ExprBase
{
public:
	string getC()
	{
		return "(" + a->getC() + " / " + b->getC() + ")";
	}
	
	Expr a, b;
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
			((ExprLiteral*)&(*a))->val
			/
			((ExprLiteral*)&(*b))->val
		);
	}
	else
	{
		auto out = new ExprQuotient;
		out->a = move(a);
		out->b = move(b);
		return Expr(out);
	}
}


class ExprNegative: public ExprBase
{
public:
	string getC()
	{
		return "(-" + a->getC() + ")";
	}
	
	Expr a;
};

Expr negative(Expr a)
{
	if (a->isIdk())
	{
		return exprIdk();
	}
	else if (a->isLiteral())
	{
		return expr(-((ExprLiteral*)&(*a))->val);
	}
	else
	{
		auto out = new ExprNegative;
		out->a = move(a);
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


