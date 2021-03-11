#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int *y;

    x = 2;
    // y = &x;

    printf("\n Conteudo de X: %d",x);
    printf("\n Conteudo de Y: %d",y);
    printf("\n Endereco de X: %d",&x);
    printf("\n Endereco de Y: %d",&y);
    printf("\n Conteudo de quem Y aponta: %d",*y);

    *y = 10;

    printf("\n Conteudo de X: %d",x);



    return 0;
}