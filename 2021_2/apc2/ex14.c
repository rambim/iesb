#include <stdio.h>
#include <stdlib.h>

void funcao1(int * a);

int main()
{
    int x=2;
    int *y;

    y = &x;
    funcao1(&x);
    printf("\n %d", x);

    funcao1(y);
    printf("\n %d", x);
    
}


void funcao1(int * a)
{
    *a = *a * 2;
}


void funcao()
{

}

void funcao(int * x)
{

}

int *  funcao()
{
    int * x;
    x = (int*)malloc(sizeof(int)*1);
    return x;
}

int * funcao(int  * x)
{
    int * y;
    y = (int*)malloc(sizeof(int)*1);
    *y = *x;
    return y;
}

