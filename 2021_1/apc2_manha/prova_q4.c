#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int total_ratos = 0, total_sapos = 0, total_coelhos = 0, qtd_total=0;
    int qtd_aux;
    char tipo;
    float pc_coelhos, pc_ratos,pc_sapos;
    
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        scanf("%d %c", &qtd_aux, &tipo);

        qtd_total = qtd_total + qtd_aux;

        switch (tipo)
        {
        case 'C':
            total_coelhos = total_coelhos + qtd_aux;
            break;
        case 'R':
            total_ratos = total_ratos + qtd_aux;
            break;
        case 'S':
            total_sapos = total_sapos + qtd_aux;
            break;
        }
    }

    pc_coelhos = total_coelhos * 100.0/(float)qtd_total;
    pc_ratos = total_ratos * 100.0/(float)qtd_total;
    pc_sapos = total_sapos * 100.0/(float)qtd_total;

    printf("\n Total de cobaias: %d",qtd_total);
    printf("\n Total de coelhos: %d",total_coelhos);
    printf("\n Total de ratos: %d",total_ratos);
    printf("\n Total de sapos: %d",total_sapos);


    printf("\n Percentual de coelhos %f",pc_coelhos);
    printf("\n Percentual de ratos %f",pc_ratos);
    printf("\n Percentual de sapos %f",pc_sapos);

    printf("\n");
    return 0;
}
