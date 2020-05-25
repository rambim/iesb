#include <stdio.h>
#include <stdlib.h>

void mostrar_vetor(int *x, int tam);
double calcula_area(double *vet, int tam, double corte);

int main()
{
    int qtd_tiras, i, achou;
    double *vet;
    double area_esperada;
    double inf, sup, meio;
    double retorno;

    while (1)
    {
        scanf("%d %lf", &qtd_tiras, &area_esperada);

        if (qtd_tiras == 0 && area_esperada == 0)
        {
            return 0;
        }

        vet = (double *)malloc(sizeof(double) * qtd_tiras);
        double maior_tira = 0;
        double area_total_tiras = 0;

        for (i = 0; i < qtd_tiras; i++)
        {
            scanf("%lf", &vet[i]);
            area_total_tiras = area_total_tiras + vet[i];
            if (vet[i] > maior_tira)
            {
                maior_tira = vet[i];
            }
        }
        //mostrar_vetor(vet,qtd_tiras);

        // printf("\n Maior tira: %d",maior_tira);

        // solução 1
        /*
        achou = 0;
        for (i = 0; i < maior_tira; i++)
        {
            //  printf("\n Calcula area cortada para corte em %d",i);
            retorno = calcula_area(vet, qtd_tiras, i);
            //  printf("\n Area cortada = %d\n",retorno);

            if (retorno == area_esperada)
            {
                if (i == 0)
                {
                    printf(":D\n");
                }
                else
                {
                    printf("%d.0000\n", i);
                }
                achou = 1;
                break;
            }
        }
*/
        //solucão 1

        // solucao 2

      //  printf("\n Area total das tiras: %lf x area esperada: %lf", area_total_tiras, area_esperada);
        if (area_total_tiras == area_esperada)
        {
            printf(":D\n");
        }
        else
        {
            if (area_total_tiras < area_esperada)
            {
                printf("-.-\n");
            }
            else
            {

                inf = 0.0;
                sup = maior_tira;
                achou = 0;
                while (sup - inf >= 0.000001)
                {
                    meio = (inf + sup) / 2.0;
                    printf("\n Calcula area com corte em %lf", meio);
                    retorno = calcula_area(vet, qtd_tiras, meio);
                    printf("\n Area calculada: %lf", retorno);
                    if (retorno == area_esperada)
                    {
                        break;
                    }
                    else if (retorno < area_esperada)
                        sup = meio;
                    else
                        inf = meio;
                }
                printf("%.4lf\n", meio);
            }
        }

        //solução 2
    }
    return 0;
}

void mostrar_vetor(int *x, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("\n%d", x[i]);
    }
}

double calcula_area(double *vet, int tam, double corte)
{
    double som = 0.0;
    int i;
    double area;
    for (i = 0; i < tam; i++)
    {
        area = vet[i] - corte;
        if (area < 0)
        {
            area = 0;
        }
        som = som + area;
    }
    return som;
}
