#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,retorno;
    char nome1[30], nome2[30];

    printf("\nDigite seu nome: ");
    gets(nome1);
    printf("\nDigite seu nome: ");
    fgets(nome2,29,stdin);

    //tirando o \n
    nome2[strlen(nome2)-1] = '\0';

    retorno = strcmp(nome1,nome2);

    if (retorno ==0)
    {
        printf("\n Nomes iguais");
    }
    else
    {
        if (retorno <0)
        {
            printf("\n %s vem antes de %s em ordem alfabetica",nome1,nome2);
        }
        else
        {
            printf("\n %s vem antes de %s em ordem alfabetica",nome2,nome1);
        }
        
    }
    

    

    // if (nome1==nome2)
    // {
    //     printf("\n Nomes iguais");
    // }
    // else
    // {
    //     printf("\n NOmes diferentes");
    // }

    // printf("\n Tamanho do nome 1 = %ld",strlen(nome1));
    // printf("\n Tamanho do nome 2 = %ld",strlen(nome2));
    

    //***********************
    // scanf("%s",nome1);

    // // printf("Nome lido: %s",nome1);

    // for(i=0;i<30;i++)
    // {
    //     printf("\nLetra: %c",nome1[i]);
    // }
    //*********************************

    // printf("\n");
    return 0;

}