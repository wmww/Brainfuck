#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	p[3] = 240;
	p[2] = 10;
	p[1] = 6;
	p[0] = 5;
	p[4] = 0;
	
	p += 1;
	
	while(*p)
	{
		p[4] = (p[2] + p[4]);
		p[2] = (p[2] + p[3]);
		p[3] = 0;
		p[0] = (p[0] + -1);
	}
	
	p[4] = (p[-1] + p[4]);
	p[-1] = -1;
	p[2] = 0;
	p[5] = (p[1] + p[5]);
	p[1] = 0;
	
	p += 4;
	
	while(*p)
	{
		p[5] = (p[0] + p[5] + -1);
		p[0] = 0;
		p[6] = (p[1] + p[6]);
		p[1] = 0;
		
		p += 5;
	}
	
	
	p += 1;
	
	while(*p)
	{
		p[2] = (((p[1] + 12) * 15) + p[2]);
		p[1] = 0;
		p[5] = (p[0] + p[5] + -1);
		p[0] = 0;
		
		p += 5;
	}
	
	p[-1] = (p[-1] + 1);
	
	p += -1;
	
	while(*p)
	{
		p[0] = (p[0] + -1);
		p[-5] = (p[-5] + 1);
		
		p += -5;
	}
	
	putchar((((p[0] + 6) * 11) + p[1]));
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
	p[0] = -1;
	p[5] = ((((p[4] + 8) * 8) + p[5]) * 1200);
	p[1] = 0;
	p[4] = 0;
	
	p += 5;
	
	while(*p)
	{
		putchar(p[2]);
		putchar(p[3]);
		putchar(p[4]);
		p[4] = p[4];
		p[3] = p[3];
		p[2] = p[2];
		p[5] = (p[0] + p[5] + -1);
		p[0] = 0;
		
		p += 5;
	}
	
	p[0] = (p[0] + 1);
	
	while(*p)
	{
		p[0] = (p[0] + -1);
		p[-5] = (p[-5] + 1);
		
		p += -5;
	}
	
}
