#include <stdio.h>

int _data[600000];
int* _p = _data;

int main(void)
{
	_p[0] += 6;
	
	// unrolled loop
	{
		_p[0] += -1;
		_p[1] += 4;
	}
	
}
