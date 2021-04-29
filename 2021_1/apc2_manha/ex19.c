#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>



int main()
{
    char nome1[30];
    char nome2[30];
    int retorno;

    printf("\n Digite o primeiro nome: ");
    __fpurge(stdin);
    fgets(nome1,28,stdin);
    nome1[strlen(nome1)-1] = '\0';

    printf("\n Digite o segundo nome: ");
    __fpurge(stdin);
    fgets(nome2,28,stdin);
    nome2[strlen(nome2)-1] = '\0';

    
    // NÃO PODE SER ASSIM 
    // if (nome1 == nome2)
    // if (&nome1[0] == &nome2[0])
    //     printf("\n Nomes iguais");
    // else
    //     printf("\n Nomes diferentes");

    retorno = strcmp(nome1,nome2);

    if (retorno==0)
        printf("\n Nomes iguais");
    else
    {
        if (retorno<0)
        {
            printf("\n %s vem antes de %s em ordem alfabetica",nome1,nome2);
        }
        else
        {
            printf("\n %s vem antes de %s em ordem alfabetica",nome2,nome1);
        }
    }


    return 0;
}

