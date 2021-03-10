#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int *y;
    
    float a;
    float *b;

    x = 2;
    y = &x;

    printf("\nConteudo de x: %d",x);
    printf("\nEndereco de x: %d",&x);

    printf("\nConteudo de y: %d",y);
    printf("\nEndereco de y: %d",&y);
    printf("\nConteudo apontado por y: %d ",*y);

    *y = 10;

    printf("\nConteudo de X: %d",x);
    printf("\n");

    return 0;

}