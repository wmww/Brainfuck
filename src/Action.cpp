#include "../h/Action.h"
#include "../h/LoopBlock.h"

class ActionAdd: public ActionBase
{
public:
	string getC()
	{
		return "_p[" + pos->getC() + "] += " + val->getC() + ";\n";
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

class ActionShift: public ActionBase
{
public:
	string getC()
	{
		return "_p += " + val->getC() + ";\n";
	}
	
	Expr val=0;
};

Action makeActionShift(Expr val)
{
	auto out = new ActionShift;
	out->val = move(val);
	return Action(out);
}

class ActionOut: public ActionBase
{
public:
	string getC()
	{
		return "putchar((char)_p[" + pos->getC() + "]);\n";
	}
	
	Expr pos=0;
};

Action makeActionOut(Expr pos)
{
	auto out = new ActionOut;
	out->pos = move(pos);
	return Action(out);
}

class ActionLoop: public ActionBase
{
public:
	string getC()
	{
		return
			"while (*_p)\n{\n"
			+ loop->getC() +
			"}\n";
		;
	}
	
	LoopBlock loop=0;
};

Action makeActionLoop(LoopBlock loop)
{
	auto out = new ActionLoop;
	out->loop = loop;
	return Action(out);
}

