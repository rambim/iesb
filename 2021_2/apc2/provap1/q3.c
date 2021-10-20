#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd_casos=0;
    int i;
    int qtd;
    char letra;

    int qtd_r=0, qtd_s=0, qtd_c=0;
    int qtd_total=0;

    scanf("%d",&qtd_casos);

    for(i=0;i<qtd_casos;i++)
    {
        scanf("%c %d ",&letra,&qtd);

        if (letra == 'C')
        {
            qtd_c = qtd_c + qtd;
        }

        if (letra == 'R')
        {
            qtd_r = qtd_r + qtd;
        }

        if (letra == 'S')
        {
            qtd_s = qtd_s + qtd;
        }

        qtd_total = qtd_total + qtd;

    }
    printf("\n Total: %d cobaias",qtd_total);
    printf("\n Total de coelhos: %d",qtd_c);
    printf("\n Total de ratos: %d",qtd_r);
    printf("\n Total de sapos: %d",qtd_s);
    printf("\n Percentual de coelhos: %.2f",qtd_c*100.0/qtd_total);
    printf("\n Percentual de ratos: %.2f",qtd_r*100.0/qtd_total);
    printf("\n Percentual de sapos: %.2f",qtd_s*100.0/qtd_total);
    printf("\n");
    return 0;
}


