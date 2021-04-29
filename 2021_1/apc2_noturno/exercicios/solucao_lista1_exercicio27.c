#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int palindromo(char * texto);
int main()
{
    char texto[100];

    printf("\n Digite um texto: ");
    __fpurge(stdin);
    fgets(texto,98,stdin);
    texto[strlen(texto)-1] = '\0';

    if (palindromo(texto))
        printf("\n Texto palindromo");
    else
        printf("\n texto nao e palindromo");

    printf("\n");
    return 0;
}


int palindromo(char * texto)
{
    int i,j;

    for(i=0,j=strlen(texto)-1;i<strlen(texto);i++,j--)
    {
        if (texto[i] != texto[j])
            return 0;
    }
    return 1;
}


