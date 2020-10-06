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

    aluno1.n1=10;
    aluno1.n2=8;
    aluno1.matricula=123;
    aluno1.idade=5;
    aluno1.media = (aluno1.n1 + aluno1.n2) / 2;




    
    printf("\n");
    return 0;
}

