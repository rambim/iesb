#include <stdio.h>
#include <stdlib.h>



int main()
{
    int * x;

    x = malloc(4);

    *x = 4;

    printf("o conteudo de x aponta e %d",*x);
    return 0;    

}