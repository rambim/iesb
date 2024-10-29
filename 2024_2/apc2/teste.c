#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    int qtd_notas_100;

    scanf("%f",&x);

    qtd_notas_100 = x / 100;

    printf("\n Quantidade de notas de 100: %d",qtd_notas_100);    


    return 0;
}