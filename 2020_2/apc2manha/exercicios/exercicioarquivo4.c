#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct resultado
{
    char cidade[40];
    long int qtd_habitantes;
} resultado;

resultado *busca_mais_populoso(char *arquivo);

int main()
{

    char arq_entrada[50];
    char arq_saida[50];
    resultado *r;

    printf("\nDigite o nome do arquivo de entrada: ");
    // fflush(stdin) //windows
    __fpurge(stdin);
    fgets(arq_entrada, 50, stdin);
    arq_entrada[strlen(arq_entrada) - 1] = '\0';

    printf("\nDigite o nome do arquivo de saida: ");
    // fflush(stdin) //windows
    __fpurge(stdin);
    fgets(arq_saida, 50, stdin);
    arq_saida[strlen(arq_saida) - 1] = '\0';

    r = busca_mais_populoso(arq_entrada);

    if (r == NULL)
    {
        printf("Sem resultado");
    }

    FILE * saida;

    saida = fopen(arq_saida,"w");

    if (saida==NULL)
    {
        printf("\n problema para criar arquivo de saida");
    }
    else
    {
        fprintf(saida,"%s %ld",r->cidade,r->qtd_habitantes);
        fclose(saida);
    }
    

    printf("\n");
    return 0;
}

resultado *busca_mais_populoso(char *arquivo)
{
    FILE *arq;
    char linha[100];
    resultado *r;
    char cidades_do_arquivo[40];
    long int qtd_habitantes_do_arquivo;

    arq = fopen(arquivo, "r");
    r = (resultado *)malloc(sizeof(resultado));
    strcpy(r->cidade, "\0");
    r->qtd_habitantes = 0;

    if (arq == NULL)
    {
        printf("\nProblemas na abertura do arquivo");
        return NULL;
    }

    while (!feof(arq))
    {
        fscanf(arq, "%s %ld", cidades_do_arquivo, &qtd_habitantes_do_arquivo);
        if (qtd_habitantes_do_arquivo>r->qtd_habitantes)
        {
            r->qtd_habitantes = qtd_habitantes_do_arquivo;
            strcpy(r->cidade,cidades_do_arquivo);
        }
    }

    fclose(arq);

    return r;
}
