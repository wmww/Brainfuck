#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	putchar(3);
	putchar(4);
	p[0] = 4;
	p[1] = 3;
	
	p += 1;
	
	while(*p)
	{
		p[0] = (-1 + p[0]);
	}
	
	putchar(p[0]);
	p[0] = p[0];
}
