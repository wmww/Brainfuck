#include "../h/utils.h"
#include "../h/Optimizer.h"

const int DATA_SIZE=600000;

const bool debug=false;

string transpileCode(string& code, int& i); //send it some source and the index after the '[', it will return the index after ']'
string transpileFile(string filename);
void showDebug(char lastCmd);
int findMatchingBrase(string& code, int start);
string currentFIle="";

int main(int argc, char ** argv)
{
	//cout << "William's brainfuck interpreter, array size is " << DATA_SIZE << endl << endl;
	
	//cout << "enter code: ";
	
	string infilename;
	string outSourceFile="transpiled/source.c";
	string outBinFile="transpiled/bin";
	
	if (argc>1)
	{
		infilename=string(argv[1]);
	}
	else
	{
		cout << "please specify a source file" << endl;
		exit(0);
	}
	
	string out = "";
	
	out+=
		"#include <stdio.h>\n"
		"int data["+to_string(DATA_SIZE)+"];\n"
		"int* p=data;\n"
		"int main(void)\n{\n";
	
	out+=transpileFile(infilename);
	
	out+="}";
	
	cout << "code:" << endl << endl << out << endl << endl;
	
	writeFile(outSourceFile, out, false);
	
	string cmd = "gcc -std=c99 '"+outSourceFile+"' -o '"+outBinFile+"'";
	
	cout << "running '"+cmd+"'" << endl;
	
	string cmdOut = runCmd(cmd);
	
	cout << cmdOut << endl;
}

string transpileFile(string filename)
{
	string code;
	
	string oldCurrentFile = currentFIle;
	
	currentFIle = getDirOfPath(currentFIle)+filename;
	
	loadFile(currentFIle, code, false);
	
	if (code.empty())
	{
		cout << "could not load '" << currentFIle << "'" << endl;
		exit(-1);
	}
	
	//int i=0;
	//string out="";
	//string out=transpileCode(code, i);
	
	/*while(i<int(code.size()))
	{
		out+=getNextBlock(code, i);
	}*/
	
	Optimizer optimizer;
	
	for (int i=0; i<int(code.size()); i++)
	{
		optimizer.add(code[i]);
	}
	
	string out=optimizer.getC();
	
	currentFIle = oldCurrentFile;
	
	return out;
}

string transpileCode(string& code, int& i)
{
	string out="";
	
	for (; i<int(code.size()) && code[i]!=']'; i++)
	{
		switch (code[i])
		{
		case '<':
			out+="p--;\n";
			break;
			
		case '>':
			out+="p++;\n";
			break;
			
		case '+':
			out+="(*p)++;\n";
			break;
			
		case '-':
			out+="(*p)--;\n";
			break;
			
		case '.':
			out+="putchar(*p);\n";
			break;
			
		case ',':
			out+="*p=getchar();\n";
			break;
			
		case '[':
			out+="while (*p)\n{\n";
			i++;
			out+=transpileCode(code, i);
			out+="}\n";
			break;
			
		case '"':
			
			int j;
			for (j=i+1; code[j]!='"'; j++)
			{
				if (j+1>=(int)code.size())
				{
					cout << "no closing quote" << endl;
					exit(-1);
				}
			}
			
			{
				string filename=code.substr(i+1, j-i-1);
				out+=transpileFile(filename);
			}
			i=j;
			break;
			
		default:
			break;
		}
	}
	
	return out;
}

int findMatchingBrase(string& code, int start)
{
	int count=0;
	int i=start;
	
	do {
		
		if (i>(int)code.size())
		{
			cout << endl << "'[' without matching ']'" << endl;
			exit(-1);
		}
		
		if (code[i]=='[')
			count++;
		else if (code[i]==']')
			count--;
			
		i++;
		
	} while(count>0);
	
	return i;
}
