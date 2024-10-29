#include <stdio.h>

int fun(int * i, int * j)
{
    *i += 3;
    *j += 5;
    return *j - *i;
}

void main()
{
    printf("%d\n", 3 + (-2) * 4);
}

