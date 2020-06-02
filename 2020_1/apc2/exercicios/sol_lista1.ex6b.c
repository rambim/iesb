#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x, y;
    int sum = 0;
    int prd = 1;
    int i = 0;
    int tamanho;
    int qtd_pares=0, qtd_impares=0;

    int *vet_pares, *vet_impares;

    do
    {
        printf("\nDigite x: ");
        scanf("%d", &x);
        printf("\nDigite Y: ");
        scanf("%d", &y);

        if (x > y)
        {
            printf("\n X maior que Y, digite novamente");
        }
    } while (x >= y);

    tamanho = y - x;

    vet_pares   = (int*)malloc(sizeof(int)*(tamanho/2)+1);
    vet_impares = (int*)malloc(sizeof(int)*(tamanho/2)+1);

    for(i=x;i<=y;i++)
    {
        if (i%2==0)
        {
            vet_pares[qtd_pares] = i;
            qtd_pares++;
        }
        else
        {
            vet_impares[qtd_impares] = i;
            qtd_impares++;
        }
        
    }

    for(i=0;i<qtd_pares;i++)
    {
        sum = sum + i;
    }

    for(i=0;i<qtd_impares;i++)
    {
        prd = prd * i;
    }

    printf("\nSomatorio: %d",sum);
    printf("\nProduto  : %d",prd);
    printf("\n");

}