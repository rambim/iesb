#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que solicite ao usuario
a quantidade de alunos.
preencha as notas 1 e 2 de cada aluno. 
calcule a media de cada aluno
mostre a media de todos alunos
*/

typedef struct aluno
{
    float n1;
    float n2;
    float media;
    long int matricula;

}aluno;

aluno preenche_aluno();
void preenche_aluno2(aluno * teste);
void mostrar_dados_aluno(aluno a);
void mostrar_dados_turma(aluno * vet, int tam);

int main()
{
    aluno *turma;
    int qtd_alunos;
    int i;

    printf("\n Digite a quantidade de alunos: ");
    scanf("%d",&qtd_alunos);

    turma = (aluno *)malloc(sizeof(aluno)*qtd_alunos);

    for(i=0;i<qtd_alunos;i++)
    {
        printf("\n Preenchendo dados do aluno %d",i+1);
        turma[i] = preenche_aluno();
    }

    mostrar_dados_turma(turma,qtd_alunos);


    return 0;
}

aluno preenche_aluno()
{
    aluno a;
    printf("\nDigite a matricula do aluno: ");
    scanf("%ld",&a.matricula);
    printf("\nDigite a N1 do aluno: ");
    scanf("%f",&a.n1);
    printf("\nDigite a N2 do aluno: ");
    scanf("%f",&a.n2);
    a.media = (a.n1 + a.n2) / 2.0;
    return a;
}

void preenche_aluno2(aluno * a)
{
    printf("\nDigite a matricula do aluno: ");
    scanf("%ld",&a->matricula);
    printf("\nDigite a N1 do aluno: ");
    scanf("%f",&a->n1);
    printf("\nDigite a N1 do aluno: ");
    scanf("%f",&a->n2);
    
    a->media = (a->n1 + a->n2) / 2.0;
}


void mostrar_dados_turma(aluno * vet, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        mostrar_dados_aluno(vet[i]);
    }
}
void mostrar_dados_aluno(aluno a)
{
    printf("\nMatricula = %ld",a.matricula);
    printf("\nN1        = %f",a.n1);
    printf("\nN2        = %f",a.n2);
    printf("\nMedia     = %f",a.media);
}
