#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int matricula;
    float * notas;
    int qtd_notas;
    float media;
}aluno;

void mostrar_aluno (aluno a);
void preenche_aluno ( aluno * a);
int main()
{
    int n,i;
    aluno * vet_alunos;

    printf("\nQuantos alunos deseja alocar? ");
    scanf("%d",&n);

    vet_alunos = (aluno*)calloc(n,sizeof(aluno));

    for(i=0;i<n;i++)
    {
        preenche_aluno(&vet_alunos[i]);
    }
    for(i=0;i<n;i++)
    {
        mostrar_aluno(vet_alunos[i]);
    }

    printf("\n");
    return 0;
}

void preenche_aluno ( aluno * a)
{
    int i;
    float som=0;
    printf("\nDigite a matricula do aluno: ");
    scanf("%d",&a->matricula);

    printf("\nQual a quantidade de notas do aluno?");
    scanf("%d",&a->qtd_notas);

    a->notas = (float*)calloc(a->qtd_notas,sizeof(float));

    for(i=0;i<a->qtd_notas;i++)
    {
        printf("\n Digite a %d nota: ",i+1);
        scanf("%f",&a->notas[i]);
        som = som + a->notas[i];
    }

    a->media = som / a->qtd_notas;
}

void mostrar_aluno (aluno a)
{
    int i;
    printf("\nMatricula: %d Qtd notas: %d",a.matricula,a.qtd_notas);
    for(i=0;i<a.qtd_notas;i++)
    {
        printf("\nNota %f",a.notas[i]);
    }
    printf("\nMedia %f",a.media);
    
}