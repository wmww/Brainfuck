#include <stdio.h>

int _data[600000];
int* _p = _data;

int main(void)
{
	_p[0] += 7;
	
	if ((-2 >= 0) != (_p[0] <= 0))
	{
		printf("fatal error: overflow detected due to wrong loop direction\n");
		return -1;
	}
	if (_p[0] % -2)
	{
		printf("fatal error: overflow detected due to overshoot of zero\n");
		return -1;
	}
	// unrolled loop
	{
		_p[0] += ((-2 * _p[0]) / 2);
		_p[1] += (_p[0] / 2);
	}
	
}
