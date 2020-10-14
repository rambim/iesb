#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 34, j;
    int *p;
    p = &i;
    (*p)++;
    j = *p + 33;

    printf("I = %d\n",i);
    printf("j = %d\n",j);


    return 0;
}
