#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int *y;
    x = 2;
    y = &x;

    printf("\nConteudo de x = %d",x);
    printf("\nEndereco de x = %d",&x);
    printf("\nConteudo de y = %d",y);
    printf("\nEndereco de y = %d",&y);
    printf("\nConteudo de quem y aponta = %d",*y);

    *y = 10;

    printf("\nConteudo de x = %d",x);
    printf("\n");

 

    return 0;
}



