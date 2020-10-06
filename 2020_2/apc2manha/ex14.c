#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    float n1,n2;
}aluno;

int main()
{
    // int x;
    // int * y;
    

    // x = 2;
    // y = &x;

    // *y = 3;

    // printf("\n %d",x);

    aluno x;
    aluno *y;

    x.n1 = 2;
    x.n2 = 3;

    y = &x;

    y->n1 = 10;

    (*y).n2 = 20;

    printf("\n %f %f",(*y).n1, (*y).n2);


    printf("\n");
    return 0;
}

