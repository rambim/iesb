#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd_casos, i;
    int qtd_ratos = 0, qtd_coelhos = 0, qtd_sapos = 0, qtd_total=0;
    float pc_ratos=0, pc_sapos=0, pc_coelhos;
    int valor;
    char tipo;

    scanf("%d", &qtd_casos);

    for (i = 0; i < qtd_casos; i++)
    {
        scanf("%d %c", &valor, &tipo);

        qtd_total = qtd_total + valor;

        switch (tipo)
        {
        case 'R':
            qtd_ratos = qtd_ratos + valor;
            break;
        case 'S':
            qtd_sapos = qtd_sapos + valor;
            break;
        case 'C':
            qtd_coelhos = qtd_coelhos + valor;
            break;
        }
    }
    
    printf("\n Total de cobaias     : %d",qtd_total);
    printf("\n Quantidade de ratos  : %d",qtd_ratos);
    printf("\n Quantidade de coelhos: %d",qtd_coelhos);
    printf("\n Quantidade de sapos  : %d",qtd_sapos);

    pc_coelhos = qtd_coelhos * 100.0 / qtd_total;
    pc_ratos = qtd_ratos * 100.0 / qtd_total;
    pc_sapos = qtd_sapos * 100.0 / qtd_total;

    printf("\n Percentual de ratos  : %.2f",pc_ratos);
    printf("\n Percentual de sapos  : %.2f",pc_sapos);
    printf("\n Percentual de coelhos: %.2f",pc_coelhos);

    printf("\n");
    return 0;
}