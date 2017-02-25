#include <stdio.h>

int _data[1000000000];
int* _p = _data+500000000;

int main(void)
{
	_p[0] += 8;
	
	while (*_p)
	{
		_p[1] += 4;
		
		if ((-1 >= 0) != (_p[1] <= 0))
		{
			printf("fatal error: overflow detected due to wrong loop direction\n");
			return -1;
		}
		if (_p[1] % -1)
		{
			printf("fatal error: overflow detected due to overshoot of zero\n");
			return -1;
		}
		// unrolled loop
		{
			_p[1] += (-_p[1]);
			_p[2] += (2 * _p[1]);
			_p[3] += (3 * _p[1]);
			_p[4] += (3 * _p[1]);
			_p[5] += _p[1];
		}
		
		_p[2] += 1;
		_p[3] += 1;
		_p[4] += -1;
		_p[6] += 1;
		
		_p += 6;
		while (*_p)
		{
			_p += -1;
		}
		_p -= 6;
		
		_p[5] += -1;
		_p += 5;
	}
	
}
