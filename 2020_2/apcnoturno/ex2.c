#include <stdio.h>
#include <stdlib.h>


void funcao1();
void funcao2(int x);
int funcao3();
int funcao4(int x);

int main()
{
    int idade;
    int qtd_pulos=10;
    funcao4(qtd_pulos);

    printf("\n Idade da funcao4 = %d",idade);

    return 0;

}

int funcao4(int x)
{
    int i,idade;
    for(i=0;i<x;i++)
    {
        printf("\n Pulei");
    }

    printf("\n Qual a sua idade? ");
    scanf("%d",&idade);

    return idade;    
}
void funcao1()
{
    printf("\npular");
}

void funcao2(int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        printf("\n pular");
    }
}

int funcao3()
{
    int altura_pulada;
    printf("\n Pulei!");
    altura_pulada = 20;

    return altura_pulada;

}







// funcao2()
// funcao3()
// funcao4()