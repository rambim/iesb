#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int compara_texto(char * a, char * b, int tam);
int main()
{
    char arquivo[50];
    char procurado[50];
    char linha[500];

    FILE * arq;

    int i;

    printf("\n Digite o nome do arquivo: ");
    __fpurge(stdin);
    fgets(arquivo,50,stdin);
    arquivo[strlen(arquivo)-1] = '\0';
    

    printf("\n Digite o texto a ser procurado: ");
    __fpurge(stdin);
    fgets(procurado,50,stdin);
    procurado[strlen(procurado)-1] = '\0';

    printf("\n Arquivo lido :%s",arquivo);

    printf("\n");

    arq = fopen(arquivo,"r");

    if (arq==NULL)
    {
        printf("\n Problemas com arquivo");
        return 0;
    }

    
    while(fgets(linha,500,arq)!=0)
    {
        for(i=0;i<(strlen(linha)-(strlen(procurado)-1));i++)
        {
            if(compara_texto(&linha[i],procurado,strlen(procurado)))
            {
                printf("\n Existe a palavra >>> %s <<< em >>> %s <<<<<",procurado,linha);
            }
        }
    }

    return 0;
}


int compara_texto(char * a, char * b, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }

    return 1;
}