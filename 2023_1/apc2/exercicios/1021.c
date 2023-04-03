#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int notas[6]={0};
    int moedas[6] = {0};
    

    double valor_total;

    scanf("%lf",&valor_total);

    notas[0] = valor_total / 100;
    valor_total = valor_total - notas[0] * 100;

    notas[1] = valor_total / 50;
    valor_total = valor_total - notas[1] * 50;

    notas[2] = valor_total / 20;
    valor_total = valor_total - notas[2] * 20;

    notas[3] = valor_total / 10;
    valor_total = valor_total - notas[3] * 10;

    notas[4] = valor_total / 5;
    valor_total = valor_total - notas[4] * 5;

    notas[5] = valor_total / 2;
    valor_total = valor_total - notas[5] * 2;

    moedas[0] = valor_total / 1;
    valor_total = valor_total - moedas[0] * 1;

    moedas[1] = valor_total / 0.5;
    valor_total = valor_total - moedas[1] * 0.5;

    moedas[2] = valor_total / 0.25;
    valor_total = valor_total - moedas[2] * 0.25;

    moedas[3] = valor_total / 0.1;
    valor_total = valor_total - moedas[3] * 0.1;

    moedas[4] = valor_total / 0.05;
    valor_total = valor_total - moedas[4] * 0.05;

    moedas[5] = valor_total / 0.01;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n",notas[0]);
    printf("%d nota(s) de R$ 50.00\n",notas[1]);
    printf("%d nota(s) de R$ 20.00\n",notas[2]);
    printf("%d nota(s) de R$ 10.00\n",notas[3]);
    printf("%d nota(s) de R$ 5.00\n",notas[4]);
    printf("%d nota(s) de R$ 2.00\n",notas[5]);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n",moedas[0]);
    printf("%d moeda(s) de R$ 0.50\n",moedas[1]);
    printf("%d moeda(s) de R$ 0.25\n",moedas[2]);
    printf("%d moeda(s) de R$ 0.10\n",moedas[3]);
    printf("%d moeda(s) de R$ 0.05\n",moedas[4]);
    printf("%d moeda(s) de R$ 0.01\n",moedas[5]);
    
    return 0;
}