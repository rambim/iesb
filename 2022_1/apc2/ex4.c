#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int *y;
    int **w;
    int ***z;

    printf("\n Endereco de x: %d",&x);
    printf("\n Endereco de y: %d",&y);
    printf("\n Endereco de w: %d",&w);
    printf("\n Endereco de z: %d",&z);

    x = 2;
    y = &x;
    w = &y;
    z = &w;

    printf("\n Conteudo de x: %d",x);
    printf("\n Conteudo de y: %d",y);
    printf("\n Conteudo de w: %d",w);
    printf("\n Conteudo de z: %d",z);

    printf("\n Apontado por y: %d",*y);
    printf("\n Apontado por w: %d",*w);
    printf("\n Apontado por z: %d",*z);

    printf("\n Apontado duplo de w: %d", **w);
    printf("\n Apontado duplo de z: %d", **z);

    printf("\n apontado triplo: %d", ***z);

    printf("\n Combo 1: &*y: %d",&*y);

    printf("\n\n");




    return 0;

}