#include <stdio.h>
int _data[600000];
int* _p = _data;
int main(void)
{
	_p[1] += 8;
	
	_p += 1;
	while (*_p)
	{
		_p[-1] += 9;
		_p[0] += -1;
	}
	
	putchar((char)_p[-1]);
	_p[1] += 1;
	_p[2] += -1;
	
	_p += 2;
	while (*_p)
	{
		_p[0] += 1;
	}
	
	_p[0] += 2;
	_p[1] += 2;
	_p[2] += 3;
	
	_p += 2;
	while (*_p)
	{
		
		_p += 1;
		while (*_p)
		{
			_p[-1] += 3;
			_p[0] += -1;
			_p[1] += 3;
		}
		
		_p += -2;
	}
	
	_p[1] += -5;
	putchar((char)_p[1]);
	_p[3] += 3;
	putchar((char)_p[3]);
	putchar((char)_p[3]);
	_p[3] += 3;
	putchar((char)_p[3]);
	_p[4] += -1;
	putchar((char)_p[4]);
	
	_p += 2;
	while (*_p)
	{
		
		_p += 1;
		while (*_p)
		{
			_p[0] += 1;
			_p[1] += 1;
			_p += 1;
		}
		
		_p += 2;
	}
	
	_p[-1] += -14;
	putchar((char)_p[-1]);
	putchar((char)_p[1]);
	_p[1] += 3;
	putchar((char)_p[1]);
	_p[1] += -6;
	putchar((char)_p[1]);
	_p[1] += -8;
	putchar((char)_p[1]);
	_p[2] += 1;
	putchar((char)_p[2]);
	_p[3] += 1;
	putchar((char)_p[3]);
}
