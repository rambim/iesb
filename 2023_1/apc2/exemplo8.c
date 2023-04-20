#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char nome[5];

    fgets(nome,5,stdin);
    // nome[strlen(nome)-1] = '\0';

    printf("\n Nome lido = %s",nome);

    return 0;
}