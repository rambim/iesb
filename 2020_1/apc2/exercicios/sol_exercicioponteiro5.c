#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    int i = 7, j = 5;
    int *p;
    int **q;
    p = &i;
    q = &p;
    c = **q + j;

    printf("I = %d\n",i);
    printf("j = %d\n",j);
    printf("c = %d\n",c);


    return 0;
}
