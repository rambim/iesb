#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    float n1,n2,media;
    long int matricula;
    int idade;
    int turno;
    int altura;
    int curso;

}aluno;

int main()
{
    aluno aluno1;

    printf("\n Digite a n1 do aluno: ");
    scanf("%f",&aluno1.n1);
    printf("\n Digite a n2 do aluno: ");
    scanf("%f",&aluno1.n2);
    aluno1.media = (aluno1.n1 + aluno1.n2) / 2;
    printf("\n Digite a idade do aluno: ");
    scanf("%d",&aluno1.idade);
    printf("\n Digite o codigo do turno do aluno: ");
    scanf("%d",&aluno1.turno);

    printf("\n Nota 1 lida    : %.2f",aluno1.n1);
    printf("\n Nota 2 lida    : %.2f",aluno1.n2);
    printf("\n Media Calculada: %.2f",aluno1.media);
    
    printf("\n");
    return 0;
}

