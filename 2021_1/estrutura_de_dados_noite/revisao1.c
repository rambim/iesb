#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x;
    int y;

    y = 2;

    x = &y;

    printf("\n Conteudo de x : %d",x);
    printf("\n Conteudo de y : %d",y);
    printf("\n Endereco de X : %d",&x);
    printf("\n Endereco de Y : %d",&y);
    printf("\n Conteudo apontado por x : %d",*x);


    return 0;
}