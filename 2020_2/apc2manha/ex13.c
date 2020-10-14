#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    float n1,n2,media;
    long int matricula;

}aluno;

int main()
{
    int i;
    aluno turma[3];
    for(i=0;i<3;i++)
    {
        printf("\n Digite a nota 1 do %d aluno: ",i+1);
        scanf("%f",&turma[i].n1);
        printf("\n Digite a nota 2 do %d aluno: ",i+1);
        scanf("%f",&turma[i].n2);
        // turma[i].media = calcula_media(turma[i].n1,turma[i].n2);
        calcula_media2(turma[i]);
        printf("\n Digite a matricula do %d aluno: ",i+1);
        scanf("%ld",&turma[i].matricula);
    }
 
    printf("\n");
    return 0;
}

void calcula_media2(aluno x)
{
    printf("\n");
    // x.media =( x.n1 + x.n2) / 2.0); // não funfa!
}

float calcula_media(float n1, float n2)
{
    return (n1+n2)/2;
}



