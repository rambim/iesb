#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd_testes;
    int i;
    int qtd;
    char tipo;
    int total_coelhos = 0;
    int total_sapos = 0;
    int total_ratos = 0;
    float percentual_ratos;
    float percentual_sapos;
    float percentual_coelhos;
    int total = 0;

    scanf("%d", &qtd_testes);

    for (i = 0; i < qtd_testes; i++)
    {
        scanf("%d %c", &qtd, &tipo);

        // if (tipo == 'R')
        //     total_ratos = total_ratos + qtd;

        // if (tipo == 'C')
        //     total_coelhos = total_coelhos + qtd;

        // if (tipo == 'S')
        //     total_sapos = total_sapos + qtd;

        switch (tipo)
        {
            case 'R':
                total_ratos = total_ratos + qtd;
                break;
            case 'C':
                total_coelhos = total_coelhos + qtd;
                break;
            case 'S':
                total_sapos = total_sapos + qtd;
                break;
            default:
                printf("\n Bixo invalido");
                break;
        }

        total = total_coelhos + total_ratos + total_sapos;
    }

    printf("\nTotal: %d cobaias",total);
    printf("\nTotal de coelhos: %d",total_coelhos);
    printf("\nTotal de sapos: %d",total_sapos);
    printf("\nTotal de ratos: %d",total_ratos);

    percentual_coelhos = total_coelhos / (total / 100.0);
    percentual_sapos = total_sapos / (total / 100.0);
    percentual_ratos = total_ratos / (total / 100.0);

    printf("\n Percentual de coelhos: %.2f %%",percentual_coelhos);
    printf("\n Percentual de sapos: %.2f %%",percentual_sapos);
    printf("\n Percentual de ratos: %.2f %%",percentual_ratos);

    return 0;
}