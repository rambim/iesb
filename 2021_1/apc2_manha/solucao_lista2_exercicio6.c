#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{

    char nome[100];
    char sexo[30];
    int idade;

    printf("\n Digite um nome: ");
    __fpurge(stdin);
    fgets(nome, 98, stdin);
    nome[strlen(nome) - 1] = '\0';

    printf("\n Digite o sexo: ");
    __fpurge(stdin);
    fgets(sexo,28,stdin);
    sexo[strlen(sexo) - 1] = '\0';

    printf("\n Digite a idade: ");
    scanf("%d",&idade);

    if (strcmp(sexo,"feminino")==0 && idade <25)
    {
        printf("\naceita");
    }
    else
    {
        printf("\n nao aceita");
    }


    printf("\n");
    return 0;
}