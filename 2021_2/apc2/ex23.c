#include <stdio.h>
#include <stdlib.h>


int main()
{

    
    int *y;

    y = malloc(4);

    *y = 2;

    printf("\n Conteudo apontado por *y = %d",*y);
    printf("\n");
    return 0;
}