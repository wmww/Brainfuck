#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	p[0] = 7;
	p[1] = 5;
	
	p += 1;
	p[0] = 0;
	p[1] = ((2 * (-p[0])) + p[1]);
}
