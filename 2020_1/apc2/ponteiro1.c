#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int * y;

    x  = 2;
    y = &x;
    printf("\n x  = %d",x);
    printf("\n &x = %d",&x);
    printf("\n y  = %d",y);
    printf("\n &y = %d",&y);
    printf("\n *y = %d",*y);

    printf("\n");
    return 0;

}