#include <stdio.h>
#include <stdlib.h>

//definição de uma struct
typedef struct aluno
{
    long int matricula;
    float n1,n2,media;    
}aluno;

//definir != declarar

void mostrar(aluno a);

int main()
{

    //declaração de uma struct
    aluno a;
    printf("\n DIgite a matricula do aluno ");
    scanf("%ld",&a.matricula);
    printf("\n Digite a Primeira nota: ");
    scanf("%f",&a.n1);
    printf("\n Digite a segunda nota: ");
    scanf("%f",&a.n2);

    a.media = (a.n1 + a.n2) / 2;

    mostrar(a);

    printf("\n Na funcao principal: ");
    printf("\n Matricula = %ld",a.matricula);
    printf("\n Nota 1 = %f",a.n1);
    printf("\n Nota 2 = %f",a.n2);
    printf("\n Media  = %f",a.media);    


    



    return 0;
}

void mostrar(aluno a)
{
    a.matricula = 456;
    printf("\n Dentro da funcao: ");
    printf("\n Matricula = %ld",a.matricula);
    printf("\n Nota 1 = %f",a.n1);
    printf("\n Nota 2 = %f",a.n2);
    printf("\n Media  = %f",a.media);    

}