/*
Faça um programa que crie um vetor de pessoas. Os dados de uma pessoa devem ser armazenados em 
um variável do tipo struct. O programa deve permitir que o usuário digite o nome de 3 pessoas e 
a seguir imprimi os dados de todas as pessoas. A struct deve armazenar os dados de idade, peso e altura.

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct pessoa
{
    char nome[30];
    int idade;
    float peso;
    float altura;
}pessoa;

void preenche_pessoa (pessoa * p);
void mostrar_pessoa(pessoa p);

int main()
{
    int i;
    pessoa pessoas[3];

    for(i=0;i<3;i++)
    {
        preenche_pessoa(&pessoas[i]);
    }

    for(i=0;i<3;i++)
    {
        mostrar_pessoa(pessoas[i]);
    }

    printf("\n");



    return 0;
}

void preenche_pessoa (pessoa * p)
{
    printf("\nDigite o nome da pessoa: ");
    __fpurge(stdin);
    fgets(p->nome,30,stdin);
    p->nome[strlen(p->nome)-1] = '\0';
    printf("\nDigite a idade da pessoa: ");
    scanf("%d",&p->idade);
    printf("\nDigite o peso da pessoa: ");
    scanf("%f",&p->peso);
    printf("\nDigite a altura da pessoa: ");
    scanf("%f",&p->altura);


}

void mostrar_pessoa(pessoa p)
{
    printf("\n Nome: %s Idade = %d Peso: %f Altura %f",p.nome,p.idade,p.peso,p.altura);
}