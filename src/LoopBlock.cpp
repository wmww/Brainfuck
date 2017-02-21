#include "../h/LoopBlock.h"

LoopBlock makeLoopBlock()
{
	return LoopBlock(new LoopBlockBase());
}

LoopBlockBase::LoopBlockBase()
{
	this->pos = expr(0);
}

void LoopBlockBase::add(char c)
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

void LoopBlockBase::add(Action a)
{
	actions.push_back(a);
}

void LoopBlockBase::mergeFrom(LoopBlock src)
{
	zeroPos();
	actions.push_back(makeActionLoop(src));
}

void LoopBlockBase::zeroPos()
{
	actions.push_back(makeActionShift(pos));
	pos = expr(0);
}

string LoopBlockBase::getC()
{
	string out="";
	
	for (auto i: actions)
	{
		out+=i->getC();
	}
	
	return out;
}

