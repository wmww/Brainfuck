#include "../h/Optimizer.h"

Optimizer::Optimizer()
{
	rootBlock.isRoot = true;
	currentBlock = &rootBlock;
}

void Optimizer::add(char c)
{
	//cout << "adding " << c << " to optimizer" << endl;
	
	switch (c)
	{
	case '[':
		currentBlock->nextLoop = makeLoop();
		currentBlock->nextLoop->nextBlock.parentLoop = currentBlock->parentLoop;
		currentBlock = &currentBlock->nextLoop->contentsBlock;
		break;
		
	case ']':
		if (currentBlock->parentLoop)
		{
			currentBlock = &currentBlock->parentLoop->nextBlock;
		}
		else
		{
			cout << "']' without '['" << endl;
		}
		break;
		
	default:
		currentBlock->appendAction(c);
	}
}

string Optimizer::getC()
{
	if (currentBlock->parentLoop)
	{
		cout << "no matching ']'" << endl;
	}
	else
	{
		string out="";
		
		out+=
			"#include <stdio.h>\n\n"
			"int data["+to_string(DATA_SIZE)+"];\n"
			"int* p = data;\n\n"
			"int main(void)\n{\n";
		
		out += indentString(rootBlock.getC());
		
		out += "}\n";
		
		return out;
	}
	
	return "// error\n";
}


