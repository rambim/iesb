#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{

    char texto[100];
    int comprimento=0;
    int i;

    printf("\n Digite um texto: ");
    fgets(texto,99,stdin);

    texto[strlen(texto)-1] = '\0';

    for(i=0;texto[i]!='\0';i++)
    {
        comprimento++;
    }

    printf("\n O comprimento da string %s = %d",texto,comprimento);


    printf("\n");
    return 0;
}