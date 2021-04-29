#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int procura_ocorrencia(char * texto, char l, int posicao);
int main()
{
    char texto[100];
    char letra;
    int posicao,retorno;

    printf("\n Digite um texto: ");
    __fpurge(stdin);
    fgets(texto,98,stdin);
    texto[strlen(texto)-1] = '\0';

    printf("\n Digite uma letra: ");
    scanf("%c",&letra);

    printf("\n Digite uma posicao ");
    scanf("%d",&posicao);

    retorno = procura_ocorrencia(texto,letra,posicao);

    if(retorno==-1)
    {
        printf("\n Nao existe ocorrencia da letra %c a partir da posicao %d no texto %s",letra,posicao,texto);
    }
    else
    {
        printf("\n A primeira ocorrencia da letra %c a partir da posicao %d do texto %s esta no indice %d",letra,posicao,texto,retorno);
    }

    printf("\n");
    return 0;
}


int procura_ocorrencia(char * texto, char l, int posicao)
{
    int i;

    for(i=posicao;i<strlen(texto);i++)
    {
        if (texto[i] == l)
            return i;
    }
    return -1;
}

