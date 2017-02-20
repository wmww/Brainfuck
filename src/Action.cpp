#include "../h/Action.h"

class ActionAdd: public ActionBase
{
public:
	string getC()
	{
		return "_p[" + pos->getC() + "] += " + val->getC();
	}
	
	Expr val, pos;
};

Action makeActionAdd(Expr val, Expr pos)
{
	auto out = new ActionAdd;
	out->val = move(val);
	out->pos = move(pos);
	return Action(out);
}

