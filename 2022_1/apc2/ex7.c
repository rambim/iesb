#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    float n1,n2,media;
    
}aluno;

void mostrar_dados_alunos(aluno a);
aluno preenche_aluno();
float media(float n1, float n2);
void calcula_media_aluno(aluno * a);

int main()
{
    aluno denisdj, skazi;

    denisdj = preenche_aluno();
    denisdj.media = media(denisdj.n1, denisdj.n2);

    preenche_aluno2(&skazi);
    calcula_media_aluno(&skazi);

    mostrar_dados_alunos(denisdj);
    mostrar_dados_alunos(skazi);

    printf("\n");
    return 0;
}

aluno preenche_aluno()
{
    aluno a;
    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&a.matricula);
    printf("\n Digite a primeira nota: ");
    scanf("%f",&a.n1);
    printf("\n Digite a segunda nota: ");
    scanf("%f",&a.n2);
    return a;
}

void preenche_aluno2 (aluno * a)
{
    printf("\n Digite a matricula do aluno: ");
    scanf("%d",&(*a).matricula);
    scanf("%d",&a->matricula);
    printf("\n Digite a primeira nota: ");
    scanf("%f",&(*a).n1);
    printf("\n Digite a segunda nota: ");
    scanf("%f",&(*a).n2);
}

void mostrar_dados_alunos(aluno a)
{
    printf("\n Matricula: %d",a.matricula);
    printf("\n N1: %f",a.n1);
    printf("\n N2: %f",a.n2);
    printf("\n Media: %f",a.media);
}

float media(float n1, float n2)
{
    float resultado;
    resultado = (n1+n2)/2.0;
    return resultado;
}

void calcula_media_aluno(aluno * a)
{
    a->media = (a->n1 + a->n2) / 2.0;
    (*a).media = ((*a).n1 + (*a).n2) / 2.0;
}



