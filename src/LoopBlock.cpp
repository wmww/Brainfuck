#include "../h/LoopBlock.h"

LoopBlock::LoopBlock(Expr pos)
{
	this->pos = pos;
}

void LoopBlock::add(char c)
{
	switch (c)
	{
	case '<':
		pos=sum(expr(-1), pos);
		break;
		
	case '>':
		pos=sum(expr(1), pos);
		break;
		
	case '+':
		add(makeActionAdd(pos, expr(1)));
		break;
		
	case '-':
		add(makeActionAdd(pos, expr(-1)));
		break;
		
	case '.':
		add(makeActionOut(pos));
		break;
		
	case ',':
		cout << "',' input operator not yet implemented" << endl;
		break;
	
	default:
		break;
	}
}

void LoopBlock::add(Action a)
{
	actions.push_back(a);
}

void LoopBlock::mergeInto(LoopBlock& in)
{
	
}

string LoopBlock::getC()
{
	string out="";
	
	for (auto i: actions)
	{
		out+=i->getC();
	}
	
	return out;
}

