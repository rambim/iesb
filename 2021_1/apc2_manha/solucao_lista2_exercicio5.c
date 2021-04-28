#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{

    char texto[100];
    int i;
    int qtd_letras=0;

    printf("\n Digite um texto: ");
    fgets(texto, 99, stdin);

    texto[strlen(texto) - 1] = '\0';

    for(i=0;i<strlen(texto);i++)
    {
        if (texto[i] >= 97 && texto[i] <= 122)
            qtd_letras++;

    }

    printf("\n Existem %d letras na string %s",qtd_letras,texto);

    printf("\n");
    return 0;
}