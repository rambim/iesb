#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>


//strcpy
int main()
{
    char nome1[30];
    char nome2[30];
    int retorno;

    printf("\n Digite o primeiro nome: ");
    __fpurge(stdin);
    fgets(nome1,28,stdin);
    nome1[strlen(nome1)-1] = '\0';

    //NÂO PODE!
    // nome2 = nome1;

    strcpy(nome2,nome1);

    printf("\n Nome1 : %s Nome2 : %s",nome1,nome2);
    return 0;
}

