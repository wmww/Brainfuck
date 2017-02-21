#include <stdio.h>
int _data[600000];
int* _p = _data;
int main(void)
{
_p[0] += 1;
_p[0] += 1;
_p[0] += 1;
_p[0] += 1;
_p[1] += 1;
_p[1] += 1;
_p += 1;
while (*_p)
{
_p[1] += 1;
_p[0] += -1;
}
putchar((char)_p[0]);
}
