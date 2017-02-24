#include <stdio.h>

int _data[600000];
int* _p = _data;

int main(void)
{
	_p[1] += 8;
	
	// unrolled loop
	{
		_p[0] += ((9 * _p[1]) / 1);
		_p[1] += ((-1 * _p[1]) / 1);
	}
	
	putchar((char)_p[0]);
	_p[2] += 1;
	_p[3] += -1;
	
	// unrolled loop
	{
		_p[3] += ((1 * _p[3]) / -1);
	}
	
	_p[3] += 2;
	_p[4] += 2;
	_p[5] += 3;
	
	_p += 5;
	while (*_p)
	{
		
		// unrolled loop
		{
			_p[0] += ((3 * _p[1]) / 1);
			_p[1] += ((-1 * _p[1]) / 1);
			_p[2] += ((3 * _p[1]) / 1);
		}
		
		_p += -1;
	}
	_p -= 5;
	
	_p[6] += -5;
	putchar((char)_p[6]);
	_p[8] += 3;
	putchar((char)_p[8]);
	putchar((char)_p[8]);
	_p[8] += 3;
	putchar((char)_p[8]);
	_p[9] += -1;
	putchar((char)_p[9]);
	
	_p += 7;
	while (*_p)
	{
		
		_p += 1;
		while (*_p)
		{
			_p[0] += 1;
			_p[1] += 1;
			_p += 1;
		}
		_p -= 1;
		
		_p += 3;
	}
	_p -= 7;
	
	_p[6] += -14;
	putchar((char)_p[6]);
	putchar((char)_p[8]);
	_p[8] += 3;
	putchar((char)_p[8]);
	_p[8] += -6;
	putchar((char)_p[8]);
	_p[8] += -8;
	putchar((char)_p[8]);
	_p[9] += 1;
	putchar((char)_p[9]);
	_p[10] += 1;
	putchar((char)_p[10]);
}
