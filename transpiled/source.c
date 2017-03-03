#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	putchar(66);
	putchar(77);
	putchar(54);
	putchar(132);
	putchar(3);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(54);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(40);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(64);
	putchar(1);
	putchar(0);
	putchar(0);
	putchar(240);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(1);
	putchar(0);
	putchar(24);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(132);
	putchar(3);
	putchar(0);
	putchar(19);
	putchar(11);
	putchar(0);
	putchar(0);
	putchar(19);
	putchar(11);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	putchar(0);
	p[0] = 0;
	p[1] = 76800;
	
	p += 1;
	
	while(*p)
	{
		putchar((p[1] + 3));
		putchar((p[2] + 5));
		putchar((p[3] + 6));
		p[3] = (p[3] + 6);
		p[2] = (p[2] + 5);
		p[1] = (p[1] + 3);
		p[4] = (p[0] + p[4] + -1);
		p[0] = 0;
		
		p += 4;
	}
	
}
