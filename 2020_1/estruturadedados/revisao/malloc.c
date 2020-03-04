#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * ptr;

    ptr = malloc(4);

    *ptr = 2;

    printf("\n *ptr = %d",*ptr);
    printf("\n ptr  = %d",ptr);
    printf("\n &ptr = %d",&ptr);
    printf("\n");
    return 0;
}