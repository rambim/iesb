#include <stdio.h>
#include <stdlib.h>

void funcao1(){
    printf("\n Felippe Giuliani");
}

void funcao2(int x){
    int i;
    for(i=0;i<x;i++)
    {
       funcao1();
    }
}

int funcao3(){
    int x=10;
    return x;
}

int funcao4(int x){
    x = 20;
    return x;
}

int main()
{
    int x=2;
    funcao1();
    printf("%d",x);

    funcao2(x);
    printf("%d",x);

    x = funcao3();
    printf("%d",x);

    x = funcao4(x);
    printf("%d",x);
    
    return 0;
}