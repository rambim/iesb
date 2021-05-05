#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{
    char texto[52];
    int i;

    printf("\n Digite um texto: ");
    __fpurge(stdin);
    fgets(texto,50,stdin);
    texto[strlen(texto)-1] = '\0';

    for(i=0;i<strlen(texto);i++)
    {
        texto[i] = texto[i] + 1;
    }

    printf("\n Resultado : %s",texto);

    printf("\n");
    return 0;
}