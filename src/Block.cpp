#include "../h/Block.h"
#include "../h/Loop.h"

void BlockBase::appendAction(char c)
{
	switch (c)
	{
	case '>':
		pos++;
		break;
		
	case '<':
		pos--;
		break;
		
	case '+':
		addToCell(pos, expr(1));
		break;
		
	case '-':
		addToCell(pos, expr(-1));
		break;
		
	case '.':
		addAction(outAction(getCell(pos).getExpr(pos)));
		break;
		
	case ',':
		{
			addAction(inAction(pos));
			auto cell = getCell(pos);
			cell.absoluteSet = false;
			cell.val = expr(0);
		}
		break;
	
	default:
		break;
	}
}
	
string BlockBase::getC()
{
	string out;
	
	for (auto i: actions)
	{
		out += i->getC();
	}
	
	vector<int> dependsList;
	vector<int> varsNeeded;
	assembleDependsList(dependsList, varsNeeded);
	
	if (!varsNeeded.empty())
	{
		cout << "vars needed not empty, this will likely cause trouble until vars are implemented" << endl;
	}
	
	for (int i=int(dependsList.size())-1; i>=0; i--)
	//for (auto i: dependsList)
	{
		out += "p[" + to_string(dependsList[i]) + "] = " + getCell(dependsList[i]).getExpr(dependsList[i])->getC() + ";\n";
		//out += "p[" + to_string(i) + "] = " + getCell(i).getExpr(i)->getC() + ";\n";
	}
	
	if (pos)
	{
		out += "\np += " + to_string(pos) + ";\n";
	}
	
	out = "\n//start of block\n{\n"+indentString(out)+"}\n";
	
	if (nextLoop)
	{
		out += nextLoop->getC();
	}
	
	return out;
}

void BlockBase::assembleDependsList(vector<int>& out, vector<int>& varsNeeded)
{
	if (!out.empty())
	{
		cout << "assembleDependsList called with out that isn't empty" << endl;
	}
	
	for (auto i: cells)
	{
		vector<int> stack;
		getDependsForCell(i.first, stack, out, varsNeeded);
		
		/*vector<int> forCell;
		getDependsForCell(i.first, forCell);
		
		for (auto j: forCell)
		{
			for (int k=0; k<int(out.size()); k++)
			{
				if (j == out[k])
				{
					out.erase(out.begin()+k);
					k--;
				}
			}
			
			out.push_back(j);
		}*/
		
	}
}

void BlockBase::getDependsForCell(int cell, vector<int>& stack, vector<int>& out, vector<int>& varsNeeded)
{
	for (auto j: varsNeeded)
	{
		if (cell == j)
		{
			return;
		}
	}
	
	for (auto j: stack)
	{
		if (cell == j)
		{
			varsNeeded.push_back(cell);
			return;
		}
	}
	
	for (auto j: out)
	{
		if (cell == j)
		{
			return;
		}
	}
	
	vector<int> firstLevel;
	
	getCell(cell).getExpr(cell)->getCellsUsed(firstLevel);
	
	stack.push_back(cell);
	
	for (auto i: firstLevel)
	{
		if (i != cell)
		{
			getDependsForCell(i, stack, out, varsNeeded);
		}
	}
	
	stack.pop_back();
	
	for (auto j: varsNeeded)
	{
		if (cell == j)
		{
			return;
		}
	}
	
	out.push_back(cell);
}

void BlockBase::addAction(Action action)
{
	actions.push_back(action);
}

BlockBase::CellChange& BlockBase::getCell(int index)
{
	if (cells.find(index) == cells.end())
	{
		if (isRoot)
			cells[index] = {true, expr(0)};
		else
			cells[index] = {false, expr(0)};
	}
	
	return cells[index];
}

void BlockBase::addToCell(int index, Expr val)
{
	CellChange& cell = getCell(index);
	cell.val = sum(cell.val, val);
}

Block BlockBase::getUnrolled()
{
	if (pos != 0)
	{
		return nullptr;
	}
	
	//Expr basePosStartVal = target->getCell(target->pos).getExpr(target->pos);
	Expr basePosStartVal = exprFromData(0);
	
	auto baseChange = getCell(0);
	
	if (baseChange.absoluteSet || baseChange.val->isZero())
	{
		return nullptr; // either endless loop or sets to zero, either way unrolling won't help
	}
	
	Expr changeToBasePerIter = baseChange.val;
	
	Expr iters = quotient(basePosStartVal, negative(changeToBasePerIter));
	
	Block out = Block(new BlockBase());
	
	for (auto i: cells)
	{
		if (i.first != 0)
		{
			if (i.second.absoluteSet)
			{
				out->cells[i.first] = {true, i.second.val};
			}
			else
			{
				out->addToCell(i.first, product(i.second.val, iters));
			}
		}
	}
	
	out->cells[0] = {true, expr(0)};
	
	return out;
}

void BlockBase::mergeFrom(Block target)
{
	if (!target->actions.empty())
	{
		cout << "BlockBase::mergeFrom called with target that has actions" << endl;
		return;
	}
	
	//cout << "BlockBase::mergeFrom is fucking broken. either fix it or don't call it." << endl;
	
	for (auto i: target->cells)
	{
		if (i.second.absoluteSet)
		{
			Expr val = i.second.val;
			replaceCellRefsWithCellVals(val);
			cells[i.first + pos] = {true, val};
		}
		else
		{
			Expr val = i.second.val;
			replaceCellRefsWithCellVals(val);
			addToCell(i.first + pos, val);
		}
	}
	
	pos+=target->pos;
}

void BlockBase::replaceCellRefsWithCellVals(Expr& val)
{
	cout << "in: " << val->getC() << endl;
	
	if (val->isFromCell())
	{
		val = getCell(val->getVal()+pos).getExpr(val->getVal()+pos);
	}
	
	for (int i=0; i<int(val->subs.size()); i++)
	{
		replaceCellRefsWithCellVals(val->subs[i]);
	}
	
	cout << "out: " << val->getC() << endl;
}

Expr BlockBase::CellChange::getExpr(int pos)
{
	return absoluteSet ?
		val
	:
		sum(val, exprFromData(pos));
}

/*
struct SubAction
{
	SubActionType type;
	Expr val;
};
*/

/*

class ActionMapAdd: public ActionBase
{
public:
	
	Action makeCopy()
	{
		auto out = new ActionMapAdd();
		*out = *this;
		return Action(out);
	}
	
	string getC()
	{
		string out;
		
		for (auto i: data)
		{
			for (auto j: i.second)
			{
				switch (j.type)
				{
				case ACTION_ADD:
					if (!j.val->isZero())
						out += "_p[" + to_string(i.first+offset) + "] += " + j.val->getC() + ";\n";
					break;
				
				case ACTION_OUT:
					out += "putchar((char)_p[" + to_string(i.first+offset) + "]);\n";
					break;
					
				case ACTION_IN:
					out += "_p[" + to_string(i.first+offset) + "] = getchar();\n";
					break;
				
				default:
					cout << "invalid sub action type" << endl;
				}
			}
		}
		
		return out;
	}
	
	bool isMapAdd() {return true;}
	
	void addSubAction(int pos, SubActionType type, Expr val)
	{
		vector<SubAction>& elem = data[pos];
		
		if (type!=ACTION_ADD)
		{
			onlyHasAddSubsBool = false;
		}
		
		if (type==ACTION_ADD && !elem.empty() && elem.back().type==ACTION_ADD)
		{
			elem.back().val = sum(elem.back().val, val);
		}
		else
		{
			data[pos].push_back(SubAction{type, val});
		}
	}
	
	bool canUnroll() {return onlyHasAddSubsBool;}
	
	void unroll(int offset)
	{
		this->offset += offset;
		
		Expr iter = negative(getNetChangeToPos(0));
		
		for (auto i = data.begin(); i != data.end(); i++)
		{
			for (auto j = i->second.begin(); j != i->second.end(); j++)
			{
				switch (j->type)
				{
				case ACTION_ADD:
					//cout << "making product of " << j.val->getC() << " and " << exprFromData(offset, &offset)->getC() << endl;
					j->val = quotient(product(j->val, exprFromData(0, &this->offset)), iter);
					//cout << j.val->getC() << endl;
					break;
					
				case ACTION_SET:
					// do nothing
					break;
					
				default:
					cout << "tried to unroll an action with a sub action that can't be unrolled" << endl;
					break;
				}
			}
		}
	}
	
	Expr getNetChangeToPos(int i)
	{
		Expr val = expr(0);
		
		auto subs = data.find(i);
		
		if (subs != data.end())
		{
			for (auto i: subs->second)
			{
				if (i.type == ACTION_SET)
				{
					val = i.val;
				}
				else if (i.type == ACTION_ADD)
				{
					val = sum(val, i.val);
;				}
			}
		}
		
		return val;
	}
	
	string getCUnrolled()
	{
		string out="";
		
		Variable var = makeVariable();
		
		if (data.find(0) == data.end())
		{
			out += "// nevermind, endless loop\n";
			out += "while (1)\n{\n";
			out += indentString(getC());
			out += "}\n";
			return out;
		}
		
		out += "int " + var->getName() + " = _p[0];\n";
		
		return out;
	}
	
	//bool onlyHasAddSubs() {return onlyHasAddSubsBool;}
	
	//std::map<int, vector<SubAction> >* getData() {return &data;}
	
	bool onlyHasAddSubsBool = true;
	std::map<int, vector<SubAction> > data;
	int offset = 0;
};

Action makeActionMapAdd()
{
	auto out = new ActionMapAdd;
	return Action(out);
}

class ActionUnrolled: public ActionBase
{
public:
	
	Action makeCopy()
	{
		auto out = new ActionUnrolled();
		*out = *this;
		out->loop = loop->makeCopy();
		return Action(out);
	}
	
	string getC()
	{
		string out = "";
		
		out += "\n";
		
		out += "if ((" + iterChangeToBasePos->getC() + " >= 0) != (_p[" + to_string(offset) + "] <= 0))\n{\n";
		out += indentString("printf(\"fatal error: overflow detected due to wrong loop direction\\n\");\nreturn -1;\n");
		out += "}\n";
		
		out += "if (_p[" + to_string(offset) + "] % " + iterChangeToBasePos->getC() + ")\n{\n";
		out += indentString("printf(\"fatal error: overflow detected due to overshoot of zero\\n\");\nreturn -1;\n");
		out += "}\n";
		
		//) == (_p[" + to_string(offset) + "] >= 0)
		
		//out += indentString("int " + var->getName() + " = _p[" + to_string(offset) + "];")
		//vector<string> conditions;
		
		//out += indentString("if (" + var->getName() + );
		
		out += "// unrolled loop\n{\n";
		out += indentString(loop->getC());
		out += "}\n\n";
		
		return out;
	}
	
	//bool canUnroll() {return loop->canUnroll();}
	bool canUnroll() {return false;}
	
	void unroll(int offset, Expr iters)
	{
		cout << "ActionUnrolled unrolling not implemented" << endl;
		offset += offset;
		//loop->unroll(offset, iters);
	}
	
	Expr getNetChangeToPos(int i)
	{
		return loop->getNetChangeToPos(i);
	}
	
	LoopBlock loop = nullptr;
	int offset = 0;
	Expr iterChangeToBasePos = nullptr;
};

class ActionLoop: public ActionBase
{
public:
	
	Action makeCopy()
	{
		auto out = new ActionLoop();
		*out = *this;
		if (out->loop)
			out->loop = out->loop->makeCopy();
		return Action(out);
	}
	
	string getC()
	{
		string out = "";
		
		out += "\n";
		
		if (offset != 0)
			out += "_p += " + to_string(offset) + ";\n";
		
		out += "while (*_p)\n{\n";
		
		out += indentString(loop->getC());
		
		if (loop->pos != 0)
			out += indentString("_p += " + to_string(loop->pos) + ";\n");
		
		out += "}\n";
		
		if (offset != 0)
			out += "_p -= " + to_string(offset) + ";\n";
			
		out += "\n";
		
		return out;
	}
	
	Expr getNetChangeToPos(int i)
	{
		return exprIdk();
	}
	
	LoopBlock loop=0;
	int offset; // the constant offset of everything
};

Action makeActionLoop(LoopBlock loop, int offset)
{
	if (loop->canUnroll())
	{
		auto out = new ActionUnrolled;
		//auto var = makeVariable();
		out->iterChangeToBasePos = loop->getNetChangeToPos(offset);
		loop->unroll(offset);
		out->offset = offset;
		out->loop = loop;
		return Action(out);
	}
	else
	{
		auto out = new ActionLoop;
		out->loop = loop;
		out->offset = offset;
		return Action(out);
	}
}

*/

/*
class ActionAdd: public ActionBase
{
public:
	string getC()
	{
		return "_p[" + to_string(pos) + "] += " + val->getC() + ";\n";
	}
	
	MergeStatus attemptMerge(shared_ptr<ActionBase> in)
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
	}
	
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
*/
