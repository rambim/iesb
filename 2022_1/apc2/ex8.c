#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x; 

    x = 2;

    // x = dobrar1(x);
    dobrar2(&x);


    printf("%d ",x);
}


void funcao1()
{

}

void funcao2(int x)
{

}

int funcao3()
{
    return 1;
}

int funcao4(int x)
{
    return x + 1;
}