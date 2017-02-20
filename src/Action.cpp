#include "../h/Action.h"

class ActionAdd: public ActionBase
{
public:
	string getC()
	{
		return "";//"_data[" + pos->getC() + "] += " + val->getC() + ";\n";
	}
	
	Expr val=0, pos=0;
};

Action makeActionAdd(Expr pos, Expr val)
{
	auto out = new ActionAdd;
	out->val = move(val);
	out->pos = move(pos);
	return Action(out);
}

class ActionOut: public ActionBase
{
public:
	string getC()
	{
		return "putchar((char)_data[" + pos->getC() + "]);\n";
	}
	
	Expr pos=0;
};

Action makeActionOut(Expr pos)
{
	auto out = new ActionOut;
	out->pos = move(pos);
	return Action(out);
}

