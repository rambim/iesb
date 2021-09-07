#include <stdio.h>
#include <stdlib.h>

int main()
{
    int notas[] = {100, 50, 20, 10, 5, 2};
    double moedas[] = {1, 0.5,0.25, 0.1, 0.05, 0.01};

    int qtd_notas[6] = {0,0,0,0,0,0};
    int qtd_moedas[6] = {0,0,0,0,0,0};

    double valor_lido;

    scanf("%lf", &valor_lido);
    valor_lido = valor_lido + 0.001;

    int i;
    int resultado;
    for (i = 0; i < 6; i++)
    {
        if (valor_lido >= notas[i])
        {
            resultado = valor_lido / notas[i];
            valor_lido = valor_lido - (resultado * notas[i]);
            qtd_notas[i] = qtd_notas[i] + resultado;
        }
    }

    for (i = 0; i < 6; i++)
    {
        if (valor_lido >= moedas[i])
        {
            resultado = valor_lido / moedas[i];
            valor_lido = valor_lido - (resultado * moedas[i]);
            qtd_moedas[i] = qtd_moedas[i] + resultado;
        }
    }

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n",qtd_notas[0]);
    printf("%d nota(s) de R$ 50.00\n",qtd_notas[1]);
    printf("%d nota(s) de R$ 20.00\n",qtd_notas[2]);
    printf("%d nota(s) de R$ 10.00\n",qtd_notas[3]);
    printf("%d nota(s) de R$ 5.00\n",qtd_notas[4]);
    printf("%d nota(s) de R$ 2.00\n",qtd_notas[5]);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n",qtd_moedas[0]);
    printf("%d moeda(s) de R$ 0.50\n",qtd_moedas[1]);
    printf("%d moeda(s) de R$ 0.25\n",qtd_moedas[2]);
    printf("%d moeda(s) de R$ 0.10\n",qtd_moedas[3]);
    printf("%d moeda(s) de R$ 0.05\n",qtd_moedas[4]);
    printf("%d moeda(s) de R$ 0.01\n",qtd_moedas[5]);
    return 0;
}