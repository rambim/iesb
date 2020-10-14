#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    float n1,n2,media;
    long int matricula;
}aluno;

int main()
{
    int x;
    int * ptr;

    x = 2;
    ptr = &x;

    *ptr = 10;

    printf("\n Valor alterado de X = %d",x);



    aluno y;
    aluno * ptr2;

    y.n1 = 10;
    y.n2 = 10;
    y.matricula = 20;

    ptr2 = &y;

    (*ptr2).n1 = 5;
    ptr2->n1 = 5;


    (*ptr2).n2 = 5;
    ptr2->n2 = 5;

    (*ptr2).media = 30;
    ptr2->media = 30;

    printf("\n Valores alterados: %f %f ",y.n1,y.n2);

    
    printf("\n");
    return 0;
}