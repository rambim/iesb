#include <stdio.h>
#include <stdlib.h>

int main()
{

    int vet[5], i;
    int qtd_pares=0, qtd_impares=0, qtd_positivos=0, qtd_negativos=0;

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &vet[i]);

        if (vet[i]<0)
        {
            qtd_negativos++;
        }
        else
        {
            if (vet[i]>0)
            {
                qtd_positivos++;
            }
        }

        if (vet[i] % 2==0)
        {
            qtd_pares++;
        }
        else{
            qtd_impares++;
        }
    }



    printf("%d valor(es) par(es)\n",qtd_pares);
    printf("%d valor(es) impar(es)\n",qtd_impares);
    printf("%d valor(es) positivo(s)\n",qtd_positivos);
    printf("%d valor(es) negativo(s)\n",qtd_negativos);
    return 0;
}