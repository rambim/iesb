/*

2) Faça um programa que leia 2 nomes do usuário e diga se os nomes são iguais. 
Observação: Não pode ser utilizado a função strcmp.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome1[30], nome2[30];

    int i;
    int diferente=0;


    printf("\nDigite o nome1: ");
    fgets(nome1,30,stdin);
    nome1[strlen(nome1)-1] = '\0';

    printf("\nDigite o nome2: ");
    fgets(nome2,30,stdin);
    nome2[strlen(nome2)-1] = '\0';

    if (strlen(nome1)!=strlen(nome2))
    {
        diferente=1;
    }
    else
    {
        for(i=0;i<strlen(nome1) && diferente==0;i++)
        {
            if (nome1[i] != nome2[i])
            {
                diferente=1;
            }
        }
    }

    if (diferente)
    {
        printf("\n Nomes diferentes");
    }
    else
    {
        printf("\n Nomes iguais");
    }
    
    



    // if (strcmp(nome1,nome2)==0)
    // {
    //     printf("\n Nomes iguais");
    // }
    // else
    // {
    //     printf("\n Nomes diferentes");
    // }

    return 0;   
}