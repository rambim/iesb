#include <stdio.h>

int main()
{
    int x;
    int *y;
   
    x = 2;
    y = &x;
 
    printf("\nConteudo de X = %d ",x);
    printf("\nEndereco de X = %d ",&x);
    printf("\nConteudo de Y = %d ",y);
    printf("\nEndereco de Y = %d ",&y);
    printf("\nConteudo de quem Y aponta = %d ",*y);
    *y = 10;
    printf("\nConteudo de X = %d",x);
    printf("\n");
    return 0;
}





