#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include <fstream>

#include <sstream>
using std::stringstream;

using std::cout;
using std::endl;
using std::cin;
using std::getline;

using std::string;

using std::vector;

const int DATA_SIZE=10000;
int data[DATA_SIZE]; // will be auto initalized to 0
int offset=0;
int min=offset, max=offset;
vector<int> stack;

bool loadFile(string filename, string& contents, bool debug);

int main(int argc, char ** argv)
{
	cout << "William's brainfuck interpreter, array size is " << DATA_SIZE << endl << endl;
	
	//cout << "enter code: ";
	
	string filename;
	
	if (argc>1)
	{
		filename=string(argv[1]);
	}
	else
	{
		cout << "please specify a source file" << endl;
		return 0;
	}
	
	string code;
	
	loadFile(filename, code, false);
	
	//getline(cin, code);
	
	for (int i=0; i<int(code.size()); i++)
	{
		switch (code[i])
		{
		case '<':
			offset--;
			if (offset<0)
			{
				cout << endl << "you went too far left" << endl;
				return 1;
			}
			min=std::min(min, offset);
			break;
			
		case '>':
			offset++;
			if (offset>=DATA_SIZE)
			{
				cout << endl << "you went too far right" << endl;
				return 1;
			}
			max=std::max(max, offset);
			break;
			
		case '+':
			data[offset]++;
			break;
			
		case '-':
			data[offset]--;
			break;
			
		case '.':
			putchar(data[offset]);
			break;
			
		case ',':
			data[offset]=getchar();
			break;
			
		case '[':
			if (data[offset])
				stack.push_back(i);
			else
			{
				int count=1;
				i++;
				
				for (; count>0; i++)
				{
					if (i>(int)code.size())
					{
						cout << endl << "'[' without matching ']'" << endl;
						return 1;
					}
					
					if (code[i]=='[')
					{
						count++;
					}
					else if (code[i]==']')
					{
						count--;
					}
				}
				
				i--;
			}
			break;
			
		case ']':
			if (data[offset])
			{
				if (stack.empty())
				{
					cout << endl << "']' without matching '['" << endl;
					return 1;
				}
				i=stack.back();
			}
			else
			{
				stack.pop_back();
			}
			
		default:
			break;
		}
		
		/*for (int i=min; i<=max; i++)
		{
			cout << data[i] << "\t";
		}
		
		cout << endl;
		
		for (int i=min; i<offset; i++)
		{
			cout << "\t";
		}
		
		cout << "|" << endl << endl;*/
	}
}

bool loadFile(string filename, string& contents, bool debug)
{
	std::fstream inFile;
	
	if (debug)
		cout << "attempting to open '" << filename << "'..." << endl;
	
	inFile.open(filename);
	
	if (!inFile.is_open())
	{
		if (debug)
			cout << "'" << filename << "' failed to open :(" << endl;
		return false;
	}
	else
	{
		if (debug)
			cout << "file opended, reading file..." << endl;
		
		stringstream strStream;
		strStream << inFile.rdbuf();	// read the file
		contents = strStream.str();	// str holds the content of the file
		inFile.close();
		
		if (debug)
			cout << "file reading done, '" << filename << "' closed" << endl;
		
		return true;
	}
}
