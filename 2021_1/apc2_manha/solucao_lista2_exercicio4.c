#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{

    char texto[100];
    int i;

    printf("\n Digite um texto: ");
    fgets(texto, 99, stdin);

    texto[strlen(texto) - 1] = '\0';

    for(i=0;i<4;i++)
    {
        printf("%c",texto[i]);
    }

    printf("\n");
    return 0;
}