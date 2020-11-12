/* Faça um programa que receba do usuário um número N inteiro positivo, e aloque um vetor de N alunos.
Um aluno é composto por nome, matricula e um vetor de notas de tamanho M;
Para cada aluno, leia seu nome, sua matricula , um valor M que corresponde a quantidade de notas 
desse aluno e as M notas desse aluno.
Construa uma função que receba por parâmetro um vetor de notas e o tamanho desse vetor e retorne 
a média dessas notas.
Na sua função principal, utilizando a função de calculo de médias criada, 
leia os dados de todos os alunos, suas respectivas M notas e diga qual a média de cada um dos alunos.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct aluno
{
    char nome[30];
    long int matricula;
    float * notas;
    int m;

}aluno;

void preenche_aluno(aluno * a);
float media(float * vet, int tam);

int main()
{
    int n,i,j;
    aluno * turma;
    printf("\n Digite N: ");
    scanf("%d",&n);

    turma = (aluno*)malloc(sizeof(aluno)*n);

    for(i=0;i<n;i++)
    {
        preenche_aluno(&turma[i]);
    }

    for(i=0;i<n;i++)
    {
        float media_do_aluno;
        media_do_aluno = media(turma[i].notas,turma[i].m);
        printf("\n Nome: %s Matricula: %ld Media: %.2f",turma[i].nome,turma[i].matricula,media_do_aluno);
        for(j=0;j<turma[i].m;j++)
        {
            printf("\n Nota %d = %.2f",j+1,turma[i].notas[j]);
        }
    }

    printf("\n");
    return 0;
}

void preenche_aluno(aluno * a)
{
    int i;
    printf("\nDigite o nome do aluno: ");
    __fpurge(stdin);
    fgets(a->nome,30,stdin);
    a->nome[strlen(a->nome)-1] = '\0';

    printf("\nDigite a matricula do aluno: ");
    scanf("%ld",&a->matricula);

    printf("\n Quantas notas o aluno %s possui?: ",a->nome);
    scanf("%d",&a->m);

    a->notas = (float*)malloc(sizeof(float)*a->m);

    for(i=0;i<a->m;i++)
    {
        printf("\n Digite a %d nota do aluno %s :",i+1, a->nome);
        scanf("%f",&a->notas[i]);
    }

}

float media(float * vet, int tam)
{
    float som=0;
    int i;

    for(i=0;i<tam;i++)
    {
        som = som + vet[i];
    }
    return (som/(float)tam);
}