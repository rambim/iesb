#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 10;
    free(ptr);
    printf("%d\n", *ptr);

    ptr=NULL;

    
    *ptr = 2;

    printf("%d\n", *ptr);

    return 0;
}