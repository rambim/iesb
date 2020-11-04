#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[30], sobrenome[30];

    printf("\n Digite seu nome: ");
    fgets(nome,30,stdin);
    nome[strlen(nome)-1] = '\0';

    printf("\n Digite seu sobrenome: ");
    fgets(sobrenome,30,stdin);
    sobrenome[strlen(sobrenome)-1] = '\0';

    strcat(nome," ");
    strcat(nome,sobrenome);

    printf("\n Nome      = %s",nome);
    printf("\n Sobrenome = %s",sobrenome);

    printf("\n");
    return 0;
}