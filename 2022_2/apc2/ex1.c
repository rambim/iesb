#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;

    for(i=2;i<5;i++)
    {
        printf("a");
        for(j=i;j<10;j++)
        {
            printf("b");
        }
        printf("c");
    }
    return 0;
}