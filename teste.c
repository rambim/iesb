#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 8;
    int b = 3;
    int c = -7;

    if ((a>3) && (b<10) || (c==2))
    {
        printf("\n V");
    }
    else
    {
        printf("\n F");
    }

    if ((a<b) || (c>1) && !(a==5))
    {
        printf("\n V");
    }
    else
    {
        printf("\n F");
    }

    if ((a%2==0) || (b%2==0) && (c%2==0))
    {
        printf("\n V");
    }
    else
    {
        printf("\n F");
    }
}