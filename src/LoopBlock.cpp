#include "../h/LoopBlock.h"


LoopBlock::LoopBlock()
{
	
}

void LoopBlock::add(char c)
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

void LoopBlock::mergeInto(LoopBlock& in)
{
	
}

