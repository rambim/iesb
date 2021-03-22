// assumindo que o endereço da variável x foi atribuído a um ponteiro px  , escreva uma expressão
//     que não usa x e divida x por 5



#include <stdio.h>
#include <stdlib.h>
int main()
{

    int x, *px = &x;
    *px = &x;
    x = 10;
    px = &x;

    mat[5][5];

    int **mat;

    

    *px = *px/5;

    printf("\n %d ",x);
    printf("\n");
    return 0;
}