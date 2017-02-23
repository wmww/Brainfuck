#include <stdio.h>

int _data[600000];
int* _p = _data;

int main(void)
{
	_p[0] += 6;
	
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 11;
	}
	
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	_p[-1] += 7;
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 11;
	}
	
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	_p[-1] += 6;
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 9;
	}
	
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	_p[-1] += 11;
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 12;
	}
	
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	_p[-1] += 3;
	putchar((char)_p[-1]);
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	_p[0] += 6;
	
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 9;
	}
	
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	_p[-1] += 5;
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 8;
	}
	
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	_p[-1] += 8;
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 8;
	}
	
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	_p[-1] += 1;
	putchar((char)_p[-1]);
	_p[-1] += -1;
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	_p[-1] += 5;
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 6;
	}
	
	
	_p += 1;
	while (*_p)
	{
		_p[-1] += 8;
		_p[0] += -1;
	}
	
	putchar((char)_p[-1]);
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	_p[0] += 1;
	putchar((char)_p[0]);
	_p[0] += -1;
	putchar((char)_p[0]);
	_p[0] += 4;
	
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 6;
	}
	
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	putchar((char)_p[-1]);
	_p[-1] += 11;
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 12;
	}
	
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	_p[-1] += 3;
	putchar((char)_p[-1]);
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	putchar((char)_p[0]);
	_p[0] += 3;
	
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 6;
	}
	
	_p[1] += 1;
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	_p[-1] += 11;
	putchar((char)_p[-1]);
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	_p[0] += 3;
	
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 6;
	}
	
	_p[1] += 1;
	putchar((char)_p[1]);
	
	_p += 1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	_p[-1] += 11;
	putchar((char)_p[-1]);
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
	}
	
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	putchar((char)_p[0]);
	_p[0] += 8;
	
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 8;
	}
	
	
	_p += 1;
	while (*_p)
	{
		_p[-1] += 5;
		_p[0] += -1;
	}
	
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 8;
	}
	
	
	_p += 1;
	while (*_p)
	{
		_p[-1] += 6;
		_p[0] += -1;
	}
	
	
	_p += -1;
	while (*_p)
	{
		_p[0] += -1;
		_p[1] += 5;
	}
	
	
	_p += 1;
	while (*_p)
	{
		_p[1] += 3;
		putchar((char)_p[1]);
		_p[2] += 5;
		putchar((char)_p[2]);
		_p[3] += 6;
		putchar((char)_p[3]);
		
		while (*_p)
		{
			_p[0] += -1;
			_p[4] += 1;
		}
		
		_p[4] += -1;
		_p += 4;
	}
	
}
