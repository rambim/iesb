#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    a=2;
    b=3;
    c=4;

    while(a<(b+c))
    {
        a = a + 3;
        b = b + 1;
        c = c + 1;

    }
    printf("\n %d %d %d",a,b,c);
}
