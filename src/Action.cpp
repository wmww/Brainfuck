#include "../h/Action.h"

class OutAction: public ActionBase
{
public:
	string getC()
	{
		return "putchar(" + val->getC() + ");\n";
	}
	
	Expr val;
};

Action outAction(Expr val)
{
	auto out = new OutAction;
	out->val = val;
	return Action(out);
}


class InAction: public ActionBase
{
public:
	string getC()
	{
		return "p[" + to_string(pos) + "] = getchar();\n";
	}
	
	int pos;
};

Action inAction(int pos)
{
	auto out = new InAction;
	out->pos = pos;
	return Action(out);
}

