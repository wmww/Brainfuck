#include "../h/utils.h"

#include <fstream>

#include <sstream>
using std::stringstream;

string getDirOfPath(string path)
{
	int i=path.size()-1;
	
	// this will break on windows
	while (i>=0 && path[i]!='/')
	{
		i--;
	}
	
	return path.substr(0, i+1);
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

bool writeFile(string filename, string& contents, bool debug)
{
	std::ofstream outFile;
	
	if (debug)
		cout << "attempting to write to '" << filename << "'..." << endl;
	
	outFile.open(filename);
	
	if (!outFile.is_open())
	{
		if (debug)
			cout << "'" << filename << "' failed to open :(" << endl;
		return false;
	}
	else
	{
		if (debug)
			cout << "file opended, writing to file..." << endl;
		
		outFile << contents;
		
		outFile.close();
		
		if (debug)
			cout << "file reading done, '" << filename << "' closed" << endl;
		
		return true;
	}
}


