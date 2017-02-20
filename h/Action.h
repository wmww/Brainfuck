#pragma once

#include "utils.h"
#include "Expr.h"

class ActionBase
{
public:
	virtual string getC()=0;
};

typedef shared_ptr<ActionBase> Action;

Action makeActionAdd(Expr pos, Expr val);
Action makeActionOut(Expr pos);

