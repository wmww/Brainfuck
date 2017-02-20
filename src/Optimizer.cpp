#include "../h/Optimizer.h"

Optimizer::Optimizer()
{
	
}

void Optimizer::add(char c)
{
	switch (c)
	{
	case '[':
		stack.push_back(LoopBlock(stack.back().pos));
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
	if (stack.size()>1)
	{
		cout << "no matching ']'" << endl;
	}
	else if (stack.size()!=1)
	{
		cout << "stack of bad length" << endl;
	}
	else
	{
		return stack[0].getC();
	}
	
	return "// error\n";
}


