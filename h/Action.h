#pragma once

#include "utils.h"
#include "Expr.h"

class ActionBase
{
public:
	virtual string getC() = 0;
};

typedef shared_ptr<ActionBase> Action;

Action outAction(Expr val);
Action inAction(int pos);
