#include <stdio.h>
#include <stdlib.h>


int main()
{

    int i=34,j;
    int * p;

    p = &i;
    (*p)++;
    j = *p +33;

    printf("j = %d",j);
    printf("\n");
    return 0;

}
