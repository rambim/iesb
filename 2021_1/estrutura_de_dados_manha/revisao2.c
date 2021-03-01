#include <stdio.h>
#include <stdlib.h>

void dobrar(int x);
void dobrar2(int *x);

int main()
{
    int x = 2;
    dobrar(x);
    printf("%d", x);

    dobrar2(&x);
    printf("%d", x);
}

void dobrar(int x)
{
    x = x * 2;
}

void dobrar2(int *x)
{
    *x = *x * 2;
}