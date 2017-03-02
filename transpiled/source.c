#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	
	//start of block
	{
		p[0] = 6;
	}
	
	//start of block
	{
		putchar(((11 * p[0]) + p[1]));
		p[1] = ((11 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		p[0] = 0;
		p[-1] = (7 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		putchar(((11 * p[0]) + p[1]));
		p[1] = ((11 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		p[0] = 0;
		p[-1] = (6 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		putchar(((9 * p[0]) + p[1]));
		p[1] = ((9 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		p[0] = 0;
		p[-1] = (11 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		putchar(((12 * p[0]) + p[1]));
		p[1] = ((12 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		putchar((3 + p[-1]));
		p[0] = 0;
		p[-1] = (3 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		putchar(0);
		putchar(0);
		putchar(0);
		putchar(0);
		putchar(0);
		p[0] = 6;
	}
	
	//start of block
	{
		putchar(((9 * p[0]) + p[1]));
		p[1] = ((9 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		putchar(p[-1]);
		putchar(p[-1]);
		putchar(p[-1]);
		p[0] = 0;
		p[-1] = (5 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		putchar(((8 * p[0]) + p[1]));
		p[1] = ((8 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		putchar(p[-1]);
		putchar(p[-1]);
		putchar(p[-1]);
		p[0] = 0;
		p[-1] = (8 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		putchar(((8 * p[0]) + p[1]));
		p[1] = ((8 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		putchar((1 + p[-1]));
		putchar(p[-1]);
		putchar(p[-1]);
		p[0] = 0;
		p[-1] = (5 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		p[1] = ((6 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		putchar(((8 * p[0]) + p[-1]));
		p[-1] = ((8 * p[0]) + p[-1]);
		p[0] = 0;
		
		p += -1;
	}
	
	//start of block
	{
		putchar(0);
		putchar(0);
		putchar(0);
		putchar(1);
		putchar(0);
		p[0] = 4;
	}
	
	//start of block
	{
		putchar(((6 * p[0]) + p[1]));
		p[1] = ((6 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		putchar(p[-1]);
		putchar(p[-1]);
		putchar(p[-1]);
		putchar(p[-1]);
		putchar(p[-1]);
		putchar(p[-1]);
		p[0] = 0;
		p[-1] = (11 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		putchar(((12 * p[0]) + p[1]));
		p[1] = ((12 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		putchar((3 + p[-1]));
		p[0] = 0;
		p[-1] = (3 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		putchar(0);
		p[0] = 3;
	}
	
	//start of block
	{
		putchar((((6 * p[0]) + 1) + p[1]));
		p[1] = (((6 * p[0]) + 1) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		putchar((11 + p[-1]));
		p[0] = 0;
		p[-1] = (11 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
		putchar(0);
		putchar(0);
		p[0] = 3;
	}
	
	//start of block
	{
		putchar((((6 * p[0]) + 1) + p[1]));
		p[1] = (((6 * p[0]) + 1) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		putchar((11 + p[-1]));
		p[0] = 0;
		p[-1] = (11 + p[-1]);
		
		p += -1;
	}
	
	//start of block
	{
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
		p[0] = 8;
	}
	
	//start of block
	{
		p[1] = ((8 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		p[-1] = ((5 * p[0]) + p[-1]);
		p[0] = 0;
		
		p += -1;
	}
	
	//start of block
	{
		p[1] = ((8 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	//start of block
	{
		p[-1] = ((6 * p[0]) + p[-1]);
		p[0] = 0;
		
		p += -1;
	}
	
	//start of block
	{
		p[1] = ((5 * p[0]) + p[1]);
		p[0] = 0;
		
		p += 1;
	}
	
	while(*p)
	{
		
		//start of block
		{
			putchar((3 + p[1]));
			putchar((5 + p[2]));
			putchar((6 + p[3]));
			p[1] = (3 + p[1]);
			p[2] = (5 + p[2]);
			p[3] = (6 + p[3]);
		}
		
		//start of block
		{
			p[4] = ((p[0] + -1) + p[4]);
			p[0] = 0;
			
			p += 4;
		}
	}
	
	
	//start of block
	{
	}
}
