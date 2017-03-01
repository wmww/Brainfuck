#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	p[1] = 1;
	
	p += 1;
	
	while(*p)
	{
		p[2] = getchar();
		p[2] = (-10 + p[2]);
		
		p += 2;
		
		while(*p)
		{
			p[0] = (-38 + p[0]);
			
			p += -3;
			
			while(*p)
			{
				p[0] = (-1 + p[0]);
				p[2] = (10 + p[2]);
			}
			
			
			p += 2;
			
			while(*p)
			{
				p[-2] = (1 + p[-2]);
				p[0] = (-1 + p[0]);
			}
			
			
			p += 1;
			
			while(*p)
			{
				p[-3] = (1 + p[-3]);
				p[0] = (-1 + p[0]);
			}
			
			
			p += -1;
		}
		
		
		p += -1;
	}
	
	p[-1] = (-1 + p[-1]);
	
	p += -2;
}
