#include <stdio.h>
#include <stdlib.h>


int main()
{

    
    int *y;

    y = malloc(sizeof(int));

    *y = 2;

    printf("\n Conteudo apontado por *y = %d",*y);
    printf("\n");
    return 0;
}