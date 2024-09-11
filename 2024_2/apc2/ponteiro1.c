#include <stdio.h>
int func(int a, int b, int * c);
void main()
{
    int x=2,y=3,z=2;
    y = func(x,y,&z);
    printf("%d", x + y + z);
}
int func(int a, int b, int * c)
{
    *c = *c + 1;
    if (*c <=4)
    {
        a = func(b+1,*c+1,&b);
    }
    return a + b + *c;
}
