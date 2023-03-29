#include <stdio.h>
#include <stdlib.h>

void dobrar(int x);
void dobrar2(int * x);


int main()
{
    int x=2;
    printf("\n Valor de X antes da funcao : %d",x);
    dobrar(x);
    printf("\n Valor de X depois da funcao : %d",x);
    dobrar2(&x);
    printf("\n Valor de X depois da funcao dobrar2 : %d",x);
    return 0;
}

void dobrar(int x)
{
    x = x * 2;
}

void dobrar2(int * x)
{
    *x = *x * 2;
}