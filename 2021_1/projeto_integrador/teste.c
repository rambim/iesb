#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct professor
{
    char nome[30];
    int matricula;
    float valor;
} professor;

int main(void)
{

    professor *professores, *leitura;
    int i;

    professores = (professor *)calloc(10, sizeof(professor));
    leitura = (professor *)calloc(10, sizeof(professor));

    for (i = 0; i < 10; i++)
    {
        strcpy(professores[i].nome, "felippe");
        professores[i].matricula = 10 * i + rand() % 10;
        professores[i].valor = rand() % 100;
    }

    for (i = 0; i < 10; i++)
    {
        printf("\n %d : Nome: %s Matricula: %d Valor : %f", i + 1, professores[i].nome, professores[i].matricula, professores[i].valor);
    }

    FILE *arq, *arq2;

    arq = fopen("professores.txt", "w");

    if (arq == NULL)
        printf("\ntreta");
    else
        fwrite(professores, 10, sizeof(professor), arq);
    fclose(arq);

    arq2 = fopen("professores.txt", "r");

    if (arq2 == NULL)
        printf("\n Problemas para ler aquivo");
    else
        fread(leitura, 10, sizeof(professor), arq2);
    fclose;

    for (i = 0; i < 10; i++)
    {
        printf("\n %d : Nome: %s Matricula: %d Valor : %f", i + 1, leitura[i].nome, leitura[i].matricula, leitura[i].valor);
    }

    return 0;
}