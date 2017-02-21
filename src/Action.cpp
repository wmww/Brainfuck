#include "../h/Action.h"
#include "../h/LoopBlock.h"

class ActionAdd: public ActionBase
{
public:
	string getC()
	{
		return "_p[" + to_string(pos) + "] += " + val->getC() + ";\n";
	}
	
	/*MergeStatus attemptMerge(shared_ptr<ActionBase> in)
	{
		if (in->isActionAdd())
		{
			if (((ActionAdd*)&(*in))->pos->equals(pos))
			{
				val = sum(((ActionAdd*)&(*in))->val, val);
				return SUCCESS;
			}
			else
			{
				return FAILURE;
			}
		}
		else
		{
			return FAILURE;
		}
	}*/
	
	Expr val=0;
	int pos=0;
};

Action makeActionAdd(int pos, Expr val)
{
	auto out = new ActionAdd;
	out->val = move(val);
	out->pos = pos;
	return Action(out);
}

class ActionShift: public ActionBase
{
public:
	string getC()
	{
		return "_p += " + to_string(val) + ";\n";
	}
	
	MergeStatus attemptMerge(shared_ptr<ActionBase> in)
	{
		return BLOCKED;
	}
	
	int val=0;
};

Action makeActionShift(int val)
{
	auto out = new ActionShift;
	out->val = val;
	return Action(out);
}

class ActionOut: public ActionBase
{
public:
	string getC()
	{
		return "putchar((char)_p[" + to_string(pos) + "]);\n";
	}
	
	/*MergeStatus attemptMerge(shared_ptr<ActionBase> in)
	{
		if (in->isActionAdd())
		{
			if (((ActionAdd*)&(*in))->pos->equals(pos))
			{
				val = sum(((ActionAdd*)&(*in))->val, val);
				return SUCCESS;
			}
			else
			{
				return FAILURE;
			}
		}
		else
		{
			return FAILURE;
		}
	}*/
	
	int pos=0;
};

Action makeActionOut(int pos)
{
	auto out = new ActionOut;
	out->pos = pos;
	return Action(out);
}

class ActionLoop: public ActionBase
{
public:
	string getC()
	{
		return
			"\n_p += " + to_string(offset) + ";\n"
			+ "while (*_p)\n{\n"
			+ indentString(
				loop->getC() + "_p += " + to_string(loop->pos) + ";\n"
			)
			+ "}\n\n";
		;
	}
	
	LoopBlock loop=0;
	int offset;
};

Action makeActionLoop(LoopBlock loop, int offset)
{
	auto out = new ActionLoop;
	out->loop = loop;
	out->offset = offset;
	return Action(out);
}

