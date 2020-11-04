#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //pode
    char nome[30] = "Felippe";

    //não pode
    // nome = "Felippe";

    //pode
    nome[0] = 'F';
    nome[1] = 'E';
    nome[2] = 'L';
    nome[3] = 'I';
    nome[4] = 'P';
    nome[5] = 'P';
    nome[6] = 'e';

    printf("\nDigite seu nome: ");
    scanf("%c",&nome[i]);


}