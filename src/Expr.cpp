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
	
	int getVal() {return val;}
	
	bool equals(Expr other)
	{
		return (other->isLiteral() && (((ExprLiteral*)&(*other))->val == val));
	}
	
	Expr getOptimized()
	{
		return expr(val);
	}
	
	int val;
};

void ExprBase::getCellsUsed(vector<int>& out)
{
	for (auto i: subs)
	{
		i->getCellsUsed(out);
	}
	
	if (isFromCell())
	{
		out.push_back(getVal());
	}
}

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
	
	int getVal() {return pos;}
	
	bool isFromCell() {return true;}
	
	Expr getOptimized()
	{
		return exprFromData(pos);
	}
	
	int pos;
};

Expr exprFromData(int pos)
{
	auto out = new ExprFromData;
	out->pos = pos;
	return Expr(out);
}


/*
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
*/

class ExprSum: public ExprBase
{
public:
	string getC()
	{
		string out;
		
		out += "(";
		
		for (int i=0; i<int(subs.size()); i++)
		{
			if (i)
			{
				out += " + ";
			}
			
			out += subs[i]->getC();
		}
		
		out += ")";
		
		return out;
	}
	
	Expr getOptimized()
	{
		vector<Expr> allSubs;
		
		for (auto i: subs)
		{
			Expr e = i->getOptimized();
			
			if (e->isSum())
			{
				for (auto j: e->subs)
				{
					allSubs.push_back(j);
				}
			}
			else
			{
				allSubs.push_back(e);
			}
		}
		
		int literalVal = 0;
		Expr out = Expr(new ExprSum);
		
		for (auto i: allSubs)
		{
			if (i->isLiteral())
			{
				literalVal += i->getVal();
			}
			else
			{
				out->subs.push_back(i);
			}
		}
		
		if (literalVal != 0)
		{
			out->subs.push_back(expr(literalVal));
		}
		
		if (out->subs.size() == 0)
		{
			return expr(0);
		}
		else if (out->subs.size() == 1)
		{
			return out->subs[0];
		}
		else
		{
			return out;
		}
	}
	
	bool isSum() {return true;}
};

Expr sum(Expr a, Expr b)
{
	/*if (a->isIdk() || b->isIdk())
	{
		return exprIdk();
	}
	else if (a->isLiteral() && b->isLiteral())
	{
		return expr(
			a->getVal()
			+
			b->getVal()
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
		
		if (a->isSum())
		{
			for (auto i: a->subs)
			{
				out->subs.push_back(i);
			}
		}
		else
		{
			out->subs.push_back(move(a));
		}
		
		if (b->isSum())
		{
			for (auto i: b->subs)
			{
				out->subs.push_back(i);
			}
		}
		else
		{
			out->subs.push_back(move(b));
		}
		
		return Expr(out);
	}*/
	
	ExprSum out;
	out.subs.push_back(a);
	out.subs.push_back(b);
	return out.getOptimized();
}


class ExprProduct: public ExprBase
{
public:
	string getC()
	{
		string out;
		
		out += "(";
		
		for (int i=0; i<int(subs.size()); i++)
		{
			if (i)
			{
				out += " * ";
			}
			
			out += subs[i]->getC();
		}
		
		out += ")";
		
		return out;
	}
	
	Expr getOptimized()
	{
		vector<Expr> allSubs;
		
		for (auto i: subs)
		{
			Expr e = i->getOptimized();
			
			if (e->isProduct())
			{
				for (auto j: e->subs)
				{
					allSubs.push_back(j);
				}
			}
			else
			{
				allSubs.push_back(e);
			}
		}
		
		int literalVal = 1;
		Expr out = Expr(new ExprProduct);
		
		for (auto i: allSubs)
		{
			if (i->isZero())
			{
				return expr(0);
			}
			else if (i->isLiteral())
			{
				literalVal *= i->getVal();
			}
			else
			{
				out->subs.push_back(i);
			}
		}
		
		if (literalVal != 1)
		{
			out->subs.push_back(expr(literalVal));
		}
		
		if (out->subs.size() == 0)
		{
			return expr(1);
		}
		else if (out->subs.size() == 1)
		{
			return out->subs[0];
		}
		else
		{
			return out;
		}
	}
	
	virtual bool isProduct() {return true;}
};

Expr product(Expr a, Expr b)
{
	/*if (a->isIdk() || b->isIdk())
	{
		return exprIdk();
	}
	else if (a->isLiteral() && b->isLiteral())
	{
		return expr(
			a->getVal()
			*
			b->getVal()
		);
	}
	else if (a->isOne())
	{
		return b;
	}
	else if (b->isOne())
	{
		return a;
	}
	else*/
	{
		auto out = new ExprProduct;
		out->subs.push_back(move(a));
		out->subs.push_back(move(b));
		return Expr(out)->getOptimized();
	}
}

Expr negative(Expr a)
{
	return product(a, expr(-1));
}

class ExprQuotient: public ExprBase
{
public:
	string getC()
	{
		return "(" + subs[0]->getC() + " / " + subs[1]->getC() + ")";
	}
	
	Expr getOptimized()
	{
		auto out = new ExprQuotient;
		
		for (auto i: subs)
		{
			out->subs.push_back(i->getOptimized());
		}
		
		return Expr(out);
	}
};

Expr quotient(Expr a, Expr b)
{
	
	/*if (a->isIdk() || b->isIdk())
	{
		return exprIdk();
	}
	else*/ if (b->isZero())
	{
		//return exprIdk();
		return expr(0);
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
			a->getVal()
			/
			b->getVal()
		);
	}
	else
	{
		auto out = new ExprQuotient;
		out->subs.push_back(move(a));
		out->subs.push_back(move(b));
		return Expr(out)->getOptimized();
	}
	
}

/*
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
*/

