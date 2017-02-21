#include "../h/utils.h"

#include <fstream>

#include <sstream>
using std::stringstream;

string indentString(const string& in, string indent)
{
	string out;
	int start=0;
	
	if (!in.empty())
		out+=indent;
	
	for (int i=0; i<int(in.size()-1); i++)
	{
		if (in[i]=='\n')
		{
			out+=in.substr(start, i-start+1);
			out+=indent;
			start=i+1;
		}
	}
	
	if (start<=int(in.size()))
		out+=in.substr(start, in.size()-start);
	
	return out;
}

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

//NOTE: I copied this from where I copied from where I copied this from somewhere on the internet. no idea how or why it works.
string runCmd(string cmd)
{
	const int bufferSize=4096;
    char buffer[bufferSize];
    std::string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed in getOutputFromCmd");
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, bufferSize, pipe) != NULL)
                result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}
