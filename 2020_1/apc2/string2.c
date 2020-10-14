#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char nome1[30];
    char nome2[30];

    printf("\n DIgite o primeiro nome: ");
    __fpurge(stdin);
    fgets(nome1,30,stdin);
    printf("\n DIgite o segundo nome: ");
    __fpurge(stdin);
    fgets(nome2,30,stdin);

    //nome1 = "felippe" // não pode!

/*
    if (nome1 == nome2)
    {
        printf("nomes iguais");           isso não pode! &nome1[0] 
                                          é sempre != de &nome2[0] 
    }
    else
    {
        printf("nomes diferentes!");
    }

*/
/*
    int igual;
    igual=1;
    for(i=0;i<strlen(nome1) || i<strlen(nome2);i++)
    {
        if (nome1[i] != nome2[i])
        {
            igual=0;
        }
    }                                 desnecessário!

    if (igual)
    {
        printf("\nnomes iguais");
    }
    else
    {
        printf("\n nomes diferentes");
    }
    
*/


    int retorno;

    retorno = strcmp(nome1,nome2);

    if (retorno ==0)
    {
        printf("\n Nomes iguais");
    }
    else
    {
        if (retorno <0)
        {
            printf("\n Nome 1 vem antes de nome 2 em ordem alfabetica");
        }
        else
        {
            printf("\n nome 2 vem antes de nome 1 em ordem alfabetica");
        }
        
    }
    

    return 0;
}