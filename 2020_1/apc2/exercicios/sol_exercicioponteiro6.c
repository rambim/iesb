#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, b = 12, c = 5;
    int *p;
    int *q;
    p = &a;
    q = &b;
    (*p)++;
    c = *p + *q;

    printf("A = %d\n",a);
    printf("B = %d\n",b);
    printf("C = %d\n",c);
    return 0;
}
