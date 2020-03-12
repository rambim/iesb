#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x;
    int * y;
    y = &x;
    printf("hello world");
    scanf("%d",y);

    printf("x = %d",x);
}