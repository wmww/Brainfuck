#include <stdio.h>

int _data[600000];
int* _p = _data;

int main(void)
{
	_p[0] += 1;
	
	// unrolled loop
	if ((1 >= 0) == (_p[0] <= 0))
	{
		_p[0] += (-_p[0]);
	}
	else
	{
		printf("fatal error: overflow detected in unrolled loop\n");
		return -1;
	}
	
}
