#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{

    char texto[100];

    printf("\n Digite um texto: ");
    fgets(texto, 99, stdin);

    texto[strlen(texto) - 1] = '\0';

    if (texto[0] == 'a' || texto[0] == 'A')
        printf("\n Texto lido : %s", texto);

    printf("\n");
    return 0;
}