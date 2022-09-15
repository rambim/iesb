
// 1. Escreva uma função que receba dois números
// inteiros retorne o menor número

#include <stdio.h>

int retorna_menor_numero(int n1, int n2);

int main()
{
    int n1,n2,retorno;

    printf("\n Digite n1: ");
    scanf("%d",&n1);
    printf("\n Digite n2: ");
    scanf("%d",&n2);

    retorno = retorna_menor_numero(n1,n2);

    if (retorno==0)
    {
        printf("\n Numeros sao iguais");
    }
    else
    {
        printf("\n %d é o menor numero",retorno);
    }



    return 0;
}

int retorna_menor_numero(int n1, int n2)
{
    if (n1 < n2)
    {
        return n1;
    }
    else
    {
        if (n2 < n1)
        {
            return n2;
        }
        else
        {
            return 0;
        }
    }
}


