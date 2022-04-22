#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 6;
    int numero;
    int qtd_positivos=0;

    while(i--)
    {
        scanf("%d",&numero);
        if (numero>=0)
            qtd_positivos++;
    }
    printf("%d valores positivos\n",qtd_positivos);
    return 0;
}