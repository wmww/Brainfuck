#include "../h/Optimizer.h"

Optimizer::Optimizer()
{
	
}

void Optimizer::add(char c)
{
	switch (c)
	{
	case '[':
		stack.push_back(Block());
		break;
		
	case ']':
		//mergeStack()
		break;
	}
}

string Optimizer::getC()
{
	return "//hello there\n";
}

Block::Block()
{
	
}

void Block::add(char c)
{
	switch (c)
	{
	case '<':
		//out+="p--;\n";
		break;
		
	case '>':
		//out+="p++;\n";
		break;
		
	case '+':
		//out+="(*p)++;\n";
		break;
		
	case '-':
		//out+="(*p)--;\n";
		break;
		
	case '.':
		//out+="putchar(*p);\n";
		break;
		
	case ',':
		//out+="*p=getchar();\n";
		break;
		
	case '[':
		//out+="while (*p)\n{\n";
		//i++;
		//out+=transpileCode(code, i);
		//out+="}\n";
		break;
	
	default:
		break;
	}
}


