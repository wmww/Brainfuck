#include <stdio.h>

int data[600000];
int* p = data;

int main(void)
{
	p[0] = 6;
	p[0] = 0;
	p[1] = ((2 * (-p[0])) + p[1]);
}
