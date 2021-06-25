#include <stdio.h>
#include <stdlib.h>

float percentual_de_igualdade(char *arquivo1, char *arquivo2);

int main()
{

    float igualdade;

    igualdade = percentual_de_igualdade("teste1.txt","teste2.txt");

    printf("\n Os arquivos sao %.2f %% iguais ",igualdade);
    printf("\n");
    return 0;
}

float percentual_de_igualdade(char *arquivo1, char *arquivo2)
{
    FILE *arq1, *arq2;
    char letra1,letra2;

    int qtd_total_caracteres_arq1=0;
    int qtd_caracteres_iguais=0;
    arq1 = fopen(arquivo1, "r");
    arq2 = fopen(arquivo2, "r");

    if (arq1 == NULL || arq2 == NULL)
    {
        printf("\nProblema na abertura dos arquivos");
    }

    else
    {
        while (!feof(arq1))
        {
            letra1 = fgetc(arq1);
            letra2 = fgetc(arq2);
            if (letra1 != EOF)
            {
               qtd_total_caracteres_arq1++;

               if (letra1==letra2)
               {
                   qtd_caracteres_iguais++;
               }
            }
        }
        fclose(arq1);
        fclose(arq2);
    }

    printf("\n Quantidade Total de Caracteres: %d",qtd_total_caracteres_arq1);
    printf("\n Quantidade Caracteres iguais  : %d",qtd_caracteres_iguais);

    return (float)qtd_caracteres_iguais/ (float)qtd_total_caracteres_arq1  * 100;

    return 0;
}