#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    
    char nome1[30] = "Felippe";
    char nome2[30] = "Felippe";

    // if (&nome1[0]==&nome2[0])
    // {
    //     printf("\nNomes iguais");
    // }
    // else
    // {
    //     printf("\nNomes diferentes");
    // }

    int retorno;
    retorno = strcmp(nome1,nome2);

    if (retorno==0)
    {
        printf("\n Nomes iguais");
    }
    else
    {
        printf("\n Nomes diferentes");
    }
    
    return 0;

}