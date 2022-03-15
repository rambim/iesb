/*

Faça um programa que receba um título e um texto, ambos inseridos pelo usuário, 
crie um arquivo que tenha como nome o título e grave nesse arquivo o texto.


*/


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

void grava_arquivo( char * titulo, char * texto);

int main()
{
    char titulo[50];
    char texto[300];

    printf("\n Digite o titulo: ");
    __fpurge(stdin);
    fgets(titulo,50,stdin);
    titulo[strlen(titulo)-1] = '\0';
    printf("\n Digite o texto: ");
    __fpurge(stdin);
    fgets(texto,300,stdin);

    grava_arquivo(titulo,texto);

    printf("\n");
    return 0;
}

void grava_arquivo( char * titulo, char * texto)
{
    FILE * arq;

    arq = fopen(titulo,"w");

    if ( arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
        return;
    }
    else
    {
        fprintf(arq,"%s",texto);
        fclose(arq);
    }
}





