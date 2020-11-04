/*
1) Faça um programa que leia o nome, sexo e a idade do usuário. Se o sexo for feminino e a idade menor que 25
imprimir: "ACEITA" caso contrário, imprimir "NÃO ACEITA";

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario
{
    char nome[30];
    char sexo[10];
    int idade;
}usuario;

int main()
{
    usuario a;

    printf("\nDigite o nome do usuario: ");
    fgets(a.nome,30,stdin);
    a.nome[strlen(a.nome)-1] = '\0';
    printf("\nDigite o sexo do usuario: ");
    fgets(a.sexo,30,stdin);
    a.sexo[strlen(a.sexo)-1] = '\0';
    printf("\nDigite a idade do usuario: ");
    scanf("%d",&a.idade);

    printf("\n Nome: %s Sexo: %s Idade: %d",a.nome,a.sexo,a.idade);

    if (strcmp(a.sexo,"feminino")==0 && a.idade<25)
    {
        printf("\n Aceita");
    }
    else
    {
        printf("\n Nao aceita");
    }
    
    printf("\n");
    return 0;
}
