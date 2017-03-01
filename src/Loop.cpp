#include "../h/Loop.h"

LoopBase::LoopBase()
{
	
}

Loop makeLoop(Block prevBlock)
{
	auto loop = Loop(new LoopBase());
	loop->contentsBlock = Block(new BlockBase);
	loop->nextBlock = Block(new BlockBase);
	loop->prevBlock = prevBlock;
	loop->contentsBlock->parentLoop = loop->shared_from_this();
	return loop;
}

string LoopBase::getC()
{
	string out;
	
	if (contentsBlock)
	{
		out += "\nwhile(*p)\n{\n";
		
		out += indentString(contentsBlock->getC());
		
		out += "}\n\n";
	}
	
	out += nextBlock->getC();
	
	return out;
}

/*
LoopBlock makeLoopBlock()
{
	return LoopBlock(new LoopBlockBase());
}

LoopBlockBase::LoopBlockBase()
{
	//this->pos = expr(0);
	//this->totalOffset = expr(0);
	
	pos = 0;
	//totalOffset = 0;
}

LoopBlock LoopBlockBase::makeCopy()
{
	auto out = new LoopBlockBase();
	out->pos = pos;
	for (auto i: actions)
	{
		out->actions.push_back(i->makeCopy());
	}
	return LoopBlock(out);
}

void LoopBlockBase::add(char c)
{
	switch (c)
	{
	case '<':
		shiftPos(-1);
		//zeroPos();
		//add(makeActionShift(expr(-1)));
		break;
		
	case '>':
		shiftPos(1);
		//zeroPos();
		//add(makeActionShift(expr(1)));
		break;
		
	case '+':
		//add(makeActionAdd(pos, expr(1)));
		addToCell(ACTION_ADD, pos, expr(1));
		break;
		
	case '-':
		//add(makeActionAdd(pos, expr(-1)));
		addToCell(ACTION_ADD, pos, expr(-1));
		break;
		
	case '.':
		//add(makeActionOut(pos));
		addToCell(ACTION_OUT, pos, expr());
		break;
		
	case ',':
		//cout << "',' input operator not yet implemented" << endl;
		addToCell(ACTION_IN, pos, expr());
		break;
	
	default:
		break;
	}
}

void LoopBlockBase::addToCell(SubActionType type, int pos, Expr val)
{
	if (actions.empty() || !actions.back()->isMapAdd())
	{
		actions.push_back(makeActionMapAdd());
	}
	
	actions.back()->addSubAction(pos, type, val);
}

void LoopBlockBase::mergeFrom(LoopBlock src)
{
	//zeroPos();
	//src->zeroPos();
	{
		actions.push_back(makeActionLoop(src, pos));
		//pos = 0;
	}
}

bool LoopBlockBase::canUnroll()
{
	if (pos != 0)
	{
		return false;
	}
	
	for (auto i: actions)
	{
		if (!i->canUnroll())
		{
			return false;
		}
	}
	
	if (!getNetChangeToPos(0)->isLiteral())
	{
		return false;
	}
	
	return true;
}

void LoopBlockBase::unroll(int offset)
{
	for (auto i: actions)
	{
		i->unroll(offset);
	}
}

Expr LoopBlockBase::getNetChangeToPos(int i)
{
	Expr a = expr(0);
	
	for (auto i: actions)
	{
		a = sum(a, i->getNetChangeToPos(0));
	}
	
	return a;
}

void LoopBlockBase::shiftPos(int dist)
{
	pos += dist;
	//totalOffset += dist;
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

*/
