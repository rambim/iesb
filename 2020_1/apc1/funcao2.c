
#include <stdio.h>
#include <stdlib.h>

void funcao1();
void funcao2(int x);
int funcao3();
int funcao4(int y);

int main()
{
    int x;

    funcao1();

    funcao2(2);

    x = funcao3();
    printf("Numero retornado pela funcao 3 = %d",x);

    x = funcao4(4);
    printf("\nNumero retornado pela funcao 4 = %d",x);


    return 0;
}


void funcao1()
{
    printf("oi");
}


void funcao2(int x)
{
    printf("Recebi o valor x = %d",x);
}


int funcao3()
{
    int numero;
    printf("\n Digite um numero: ");
    scanf("%d",&numero);
    return numero;
}


int funcao4(int y)
{
    int retorno;
    retorno = y * 2;
    return retorno;
}

