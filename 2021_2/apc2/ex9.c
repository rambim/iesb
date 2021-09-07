#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int *y;

    x = 2;
    y = &x;

    printf("\nConteudo de X: %d",x);
    printf("\nEndereco de X: %d",&x);
    printf("\nConteudo de Y: %d",y);
    printf("\nEndereco de Y: %d",&y);
    printf("\nApontado p  Y: %d",*y);

    printf("\n");
    return 0;
    
}


