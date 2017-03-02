#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	
	//start of block
	{
		p[1] = 8;
		
		p += 1;
	}
	
	while(*p)
	{
		
		//start of block
		{
			p[0] = (p[0] + -1);
			p[-1] = (p[-1] + 9);
		}
	}
	
	
	//start of block
	{
		putchar(p[-1]);
		p[-1] = p[-1];
		p[1] = (p[1] + 1);
		p[2] = (p[2] + -1);
		
		p += 2;
	}
	
	while(*p)
	{
		
		//start of block
		{
			p[0] = (p[0] + 1);
		}
	}
	
	
	//start of block
	{
		p[0] = (p[0] + 2);
		p[1] = (p[1] + 2);
		p[2] = (p[2] + 3);
		
		p += 2;
	}
	
	while(*p)
	{
		
		//start of block
		{
			
			p += 1;
		}
		
		while(*p)
		{
			
			//start of block
			{
				p[0] = (p[0] + -1);
				p[-1] = (p[-1] + 3);
				p[1] = (p[1] + 3);
			}
		}
		
		
		//start of block
		{
			
			p += -2;
		}
	}
	
	
	//start of block
	{
		putchar((p[1] + -5));
		putchar((p[3] + 3));
		putchar((p[3] + 3));
		putchar((p[3] + 6));
		putchar((p[4] + -1));
		p[1] = (p[1] + -5);
		p[2] = p[2];
		p[3] = (p[3] + 6);
		p[4] = (p[4] + -1);
		
		p += 2;
	}
	
	while(*p)
	{
		
		//start of block
		{
			
			p += 1;
		}
		
		while(*p)
		{
			
			//start of block
			{
				p[0] = (p[0] + 1);
				p[1] = (p[1] + 1);
				
				p += 1;
			}
		}
		
		
		//start of block
		{
			
			p += 2;
		}
	}
	
	
	//start of block
	{
		putchar((p[-1] + -14));
		putchar(p[1]);
		putchar((p[1] + 3));
		putchar((p[1] + -3));
		putchar((p[1] + -11));
		putchar((p[2] + 1));
		putchar((p[3] + 1));
		p[-1] = (p[-1] + -14);
		p[1] = (p[1] + -11);
		p[2] = (p[2] + 1);
		p[3] = (p[3] + 1);
		
		p += 3;
	}
}
