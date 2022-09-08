#include <stdio.h>
#include <stdlib.h>


void funcao1(int a, int b)
{
    int temp=a;
    a =b;
    b=temp;
}

int funcao2(int a, int b, int * c)
{
    *c = a-b;
    return a*(b+1);
}

int main()
{
    int x,y,w,z;
    x=5;
    y=4;
    funcao1(x,y);
    z= funcao2(x,y,&w);
    printf("\n %d",z);
    return 0;
}