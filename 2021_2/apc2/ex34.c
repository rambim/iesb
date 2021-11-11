#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrar_vogais(char * linha);
int vogal(char letra);

int main()
{

    FILE *arq;

    char linha[10000];

    arq = fopen("teste.txt", "r");

    if (arq == NULL)
    {
        printf("\n Problemas na leitura do arquivo");
    }
    else
    {
        while (fgets(linha, 100, arq) != NULL)
        {
            // printf("Linha lida: %s", linha);
            mostrar_vogais(linha);
            printf("\n");
        }

        fclose(arq);
    }
    printf("\n");
    return 0;
}


int vogal(char letra)
{
    char vet[] = "AEIOUaeiou";
    int i;

    for(i=0;i<strlen(vet);i++)
    {
        if (letra==vet[i])
            return 1;
    }
    return 0;
}


void mostrar_vogais(char * linha)
{
    int i;

    for(i=0;i<strlen(linha);i++)
    {
        if (vogal(linha[i]))
        {
            printf("%c ",linha[i]);
        }
    }
}