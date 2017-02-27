#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	putchar(3);
	putchar(4);
	p[0] = 4;
	p[1] = 3;
}
