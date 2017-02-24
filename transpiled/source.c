#include <stdio.h>

int _data[600000];
int* _p = _data;

int main(void)
{
	_p[0] += 1;
	
	if ((1 >= 0) != (_p[0] <= 0))
	{
		printf("fatal error: overflow detected due to wrong loop direction\n");
		return -1;
	}
	// unrolled loop
	{
		_p[0] += (-_p[0]);
	}
	
}
