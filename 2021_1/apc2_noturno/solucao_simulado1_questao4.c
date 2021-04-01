// Faça um procedimento que recebe 3 valores inteiros por parâmetro e
// retorna-os ordenados em ordem crescente.

#include <stdio.h>
#include <stdlib.h>

typedef struct grupo
{
    int n1, n2, n3;
} grupo;

grupo ordenar(int n1, int n2, int n3);

int main()
{
    int n1, n2, n3;

    grupo a;

    printf("\n Digite n1: ");
    scanf("%d", &n1);
    printf("\n Digite n2: ");
    scanf("%d", &n2);
    printf("\n Digite n3: ");
    scanf("%d", &n3);

    a = ordenar(n1,n2,n3);

    printf("\n Os numeros em ordem: %d <= %d <= %d",a.n1,a.n2,a.n3);

    printf("\n");
    return 0;
}

grupo ordenar(int n1, int n2, int n3)
{
    grupo retorno;

    /*
    n1 , n2 , n3;
    n1 , n3 , n2;
    n2 , n1 , n3;
    n2 , n3 , n1;
    n3 , n1 , n2;
    n3 , n2 , n1;
    */
    if (n1 <= n2 && n2 <= n3)
    {
        retorno.n1 = n1;
        retorno.n2 = n2;
        retorno.n3 = n3;
    }
    else
    {
        if (n1 <= n3 && n3 <= n2)
        {
            retorno.n1 = n1;
            retorno.n2 = n3;
            retorno.n3 = n2;
        }
        else
        {
            if (n2 <= n1 && n1 <= n3)
            {
                retorno.n1 = n2;
                retorno.n2 = n1;
                retorno.n3 = n3;
            }
            else
            {
                if (n2 <= n3 && n3 <= n1)
                {
                    retorno.n1 = n2;
                    retorno.n2 = n3;
                    retorno.n3 = n1;
                }
                else
                {
                    if (n3 <= n1 && n1 <= n2)
                    {
                        retorno.n1 = n3;
                        retorno.n2 = n1;
                        retorno.n3 = n2;
                    }
                    else
                    {
                        retorno.n1 = n3;
                        retorno.n2 = n2;
                        retorno.n3 = n1;
                    }
                }
            }
        }
    }
    return retorno;
}