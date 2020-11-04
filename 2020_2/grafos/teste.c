#include <stdio.h>
#include <stdlib.h>

int main()
{

    int * x,*y;
    int z = 2;


    x = &z;
    y = &z;

    // free(x);

    printf("Conteudo de quem y aponta: %d",*y);

    printf("\n");

    return 0;





}