#include <stdio.h>

int _data[600000];
int* _p = _data;

int main(void)
{
	_p[1] += 6;
	
	_p += 1;
	while (*_p)
	{
		_p[1] += 5;
		
		// unrolled loop
		{
			_p[1] += (-1 * _p[32767]);
			_p[2] += (4 * _p[32767]);
		}
		
		_p[0] += -1;
	}
	
}
