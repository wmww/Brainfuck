#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	
	//start of block
	{
		p[-1] = (2 * p[0]);
		p[1] = (2 * p[0]);
		p[2] = (3 * p[0]);
		p[0] = 0;
	}
}
