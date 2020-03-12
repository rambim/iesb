#include <stdio.h>
#include <stdlib.h>

void dobrar1(int x);
void dobrar2(int * x);

int main()
{
    int x = 2;

    printf("\n %d" ,x); // 2
    dobrar1(x);
    printf("\n %d",x);
    dobrar2(&x);
    printf("\n %d",x);
    printf("\n");
    return 0;
}

void dobrar1(int x)
{
    printf("\n Dentro da funcao = %d",x);
    x = x*2;
    printf("\n Dentro da funcao = %d",x);
}

void dobrar2(int * x)
{
    *x = *x * 2;
}