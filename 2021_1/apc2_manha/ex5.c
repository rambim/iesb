#include <stdio.h>
#include <stdlib.h>


void dobrar(int x);
void dobrar2(int * x);

int main()
{
    int x;
    x = 2;
    dobrar(x);
    printf("\n fora da funcao: %d",x);
    dobrar2(&x);
    printf("\n fora da funcao dobrar2: %d",x);
    return 0;
}


void dobrar(int x)
{
    x = x * 2;
    printf("\n dentro da funcao: %d",x);
}

void dobrar2(int * x)
{
    *x = *x * 2;
}

