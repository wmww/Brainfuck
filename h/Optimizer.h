#pragma once

#include "utils.h"

class Optimizer
{
public:
	Optimizer();
	void add(char);
	string getC();
	
private:
	
	enum StepType
	{
		ADD,
		SET,
		OUT,
		IN,
	};

	struct Step
	{
		StepType type;
		int val; // not used for in and out
		int i; // reletive index
	};

};
