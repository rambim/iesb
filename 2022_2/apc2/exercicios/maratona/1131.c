#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcao;
    int inter, gremio;
    int qtd_vitorias_inter = 0, qtd_vitorias_gremio = 0;
    int empates = 0;
    int qtd_grenais = 0;

    do
    {
        qtd_grenais++;
        scanf("%d %d", &inter, &gremio);
        if (inter > gremio)
        {
            qtd_vitorias_inter++;
        }
        else
        {
            if (inter < gremio)
            {
                qtd_vitorias_gremio++;
            }
            else
            {
                empates++;
            }
        }

        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &opcao);

    } while (opcao == 1);
    printf("%d grenais\n", qtd_grenais);
    printf("Inter:%d\n", qtd_vitorias_inter);
    printf("Gremio:%d\n", qtd_vitorias_gremio);
    printf("Empates:%d\n", empates);
    if (qtd_vitorias_inter > qtd_vitorias_gremio)
    {
        printf("Inter venceu mais\n");
    }
    else
    {
        if (qtd_vitorias_gremio > qtd_vitorias_inter)
        {
            printf("Gremio venceu mais\n");
        }
        else
        {
            printf("Nao houve vencedor\n");
        }
    }
}