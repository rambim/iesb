#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x=2;
    int * y;

    y = &x;

    printf("\nx = %d",x);
    printf("\n&x = %d",&x);
    printf("\ny = %d",y);
    printf("\n&y = %d",&y);
    printf("\n*y = %d",*y);

    printf("\n");

    return 0;
}