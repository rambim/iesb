#include <stdio.h>
#include <stdlib.h>

double calcula_area(double * vet, int tam, double corte);

int main()
{

    int qtd_tiras, i, achou;
    double area_esperada;
    double *vet;
    double maior_tira;
    double area_total_tiras;
    double inf, sup, meio;
    double retorno;

    FILE * arq,*arq2;

    arq = fopen("seu_madruga.in","r");
    arq2 = fopen("resposta.out","w");

    if ( arq==NULL)
    {
        return -1;
    }

    while (1)
    {
        fscanf(arq,"%d %lf", &qtd_tiras, &area_esperada);

        if (qtd_tiras == 0 && area_esperada == 0)
        {
            return 0;
        }

        vet = (double *)malloc(sizeof(double) * qtd_tiras);

        maior_tira = 0;
        area_total_tiras = 0;

        for (i = 0; i < qtd_tiras; i++)
        {
            fscanf(arq,"%lf", &vet[i]);
            area_total_tiras = area_total_tiras + vet[i];

            if (vet[i] > maior_tira)
            {
                maior_tira = vet[i];
            }
        }

        if (area_total_tiras == area_esperada)
        {
            fprintf(arq2,":D\n");
        }
        else
        {
            if (area_total_tiras < area_esperada)
            {
                fprintf(arq2,"-.-\n");
            }
            else
            {
                inf = 0.0;
                sup = maior_tira;

                while (sup - inf >= 0.0000001)
                {
                    meio = (inf + sup) / 2.0;

                    retorno = calcula_area(vet,qtd_tiras,meio);

                    if (retorno == area_esperada)
                    {
                        break;
                    }
                    else
                    {
                        if (retorno < area_esperada)
                        {
                            sup = meio;
                        }
                        else
                        {
                            inf = meio;
                        }
                    }
                }

                fprintf(arq2,"%.4lf\n",meio);

            }
        }
        
        
    }
    fclose(arq);
    fclose(arq2);
    return 0;
}


double calcula_area(double * vet, int tam, double corte)
{
    double som=0.0;
    int i;

    double area;

    for(i=0;i<tam;i++)
    {
        area = vet[i] - corte;
        if (area < 0)
        {
            area =0;
        }
        som = som + area;
    }

    return som;
}


