#include <stdio.h>
int data[600000];
int* p=data;
int main(void)
{
(*p)++;
(*p)++;
(*p)++;
(*p)++;
(*p)++;
while (*p)
{
p++;
(*p)++;
p++;
(*p)++;
p--;
p--;
(*p)--;
}
p++;
while (*p)
{
while (*p)
{
p++;
p++;
p++;
(*p)++;
p--;
p--;
p--;
(*p)--;
}
p++;
while (*p)
{
p++;
p++;
p++;
(*p)++;
p--;
p--;
p--;
(*p)--;
}
p++;
*p=getchar();
p++;
(*p)--;
}
p++;
while (*p)
{
while (*p)
{
p--;
p--;
p--;
(*p)++;
p++;
p++;
p++;
(*p)--;
}
p--;
p--;
putchar(*p);
p--;
(*p)--;
}
}