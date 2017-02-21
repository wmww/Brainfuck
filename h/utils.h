#pragma once

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

#include <iostream>
using std::cout;
using std::endl;

#include <memory>
using std::unique_ptr;
using std::shared_ptr;

string indentString(const string& in, string indent="\t");

bool loadFile(string filename, string& contents, bool debug=false);
bool writeFile(string filename, string& contents, bool debug=false);

string getDirOfPath(string path);

string runCmd(string cmd);
