#include <stdio.h>
#include <stdlib.h>



int dobrar(int x)
{
   return x * 2;
}

int main()
{
    int x = 2;

    x = dobrar(x);

    printf("\n O Valor de X = %d",x);
    return 0;
}

