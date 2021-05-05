#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int esta_contido(char * texto1, char * texto2);

int main()
{
    char texto1[100];
    char texto2[100];

    printf("\n Digite o primeiro texto: ");
    __fpurge(stdin);
    fgets(texto1,98,stdin);
    texto1[strlen(texto1)-1] = '\0';

    printf("\n Digite o segundo texto: ");
    __fpurge(stdin);
    fgets(texto2,98,stdin);
    texto2[strlen(texto2)-1] = '\0';

    if (esta_contido(texto1,texto2))
        printf("\n O texto 2 esta contido no final do texto 1");
    else
        printf("\n O texto 2 nao esta contido no texto 1");


    printf("\n");
    return 0;
}

int esta_contido(char * texto1, char * texto2)
{
    if (strlen(texto2)>strlen(texto1))
        return 0;

    int i,j;

    for(i=strlen(texto1)-1,j=strlen(texto2)-1;j>=0;i--,j--)
    {
        if (texto1[i] != texto2[j])
            return 0;
    }
    return 1;
}



