#include <stdio.h>
#include <stdlib.h>

void funcao1();

int main()
{

    int variavel;
    funcao1();
    int n1 = 2;
    variavel = funcao2(n1,3)  ;

    return 0;
}

void funcao1()
{
    int n1,n2,resultado;

    printf("\n Digite o primeiro numero: ");
    scanf("%d",&n1);
    printf("\n Digite o segundo numero: ");
    scanf("%d",&n2);

    resultado = n1 + n2;

    printf("\n O resultado = %d",resultado);

}


int funcao2(int n1, int n2)
{
    int resultado;
    resultado = n1 + n2;
    return resultado;
}