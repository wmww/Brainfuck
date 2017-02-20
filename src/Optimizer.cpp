#include "../h/Optimizer.h"

Optimizer::Optimizer()
{
	
}

void Optimizer::add(char c)
{
	switch (c)
	{
	case '[':
		stack.push_back(LoopBlock());
		break;
		
	case ']':
		if (stack.size()>=2)
		{
			stack[stack.size()-2].mergeInto(stack[stack.size()-1]);
			stack.pop_back();
		}
		else
		{
			cout << "']' without '['" << endl;
		}
		break;
		
	default:
		stack.back().add(c);
	}
}

string Optimizer::getC()
{
	return "//hello there\n";
}


