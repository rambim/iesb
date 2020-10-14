/*
Faça uma função que retorne a posição de um dado caracter dentro de uma string.
*/
int posicao(char * texto, int tam_texto, char procurado);

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

int main()
{
    char texto[50];
    char letra;

    printf("\n Digite o texto: ");
    __fpurge(stdin);
    fgets(texto,50,stdin);
    texto[strlen(texto)-1] = '\0';
    printf("\n Digite qual letra deseja buscar:  ");
    scanf("%c",&letra);

    printf("\n A letra %c esta na posicao %d do texto",letra,posicao(texto,strlen(texto),letra));
    printf("\n");
    return 0;
}

int posicao(char * texto, int tam_texto, char procurado)
{
    int i;

    for(i=0;i<tam_texto;i++)
    {
        if (texto[i]==procurado)
        {
            return (i+1);
        }
    }
}