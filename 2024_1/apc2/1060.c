#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i;
    float valor;
    int qtd_positivos =0;
    float positivos[100];
    

    for(i=0;i<6;i++)
    {
        scanf("%f",&valor);
        if (valor > 0)
        {
            positivos[qtd_positivos] = valor;
            qtd_positivos++;
        }
    }

    printf("%d valores positivos\n",qtd_positivos);

    for(i=0;i<qtd_positivos;i++)
    {
        printf("Valor: %f\n",positivos[i]);
    }
    return 0;
}