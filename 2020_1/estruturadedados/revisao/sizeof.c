#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho;

    int x;

    tamanho = sizeof(x);

    printf("\n Tamanho o x= %d",tamanho);

    tamanho= 0;

    tamanho=sizeof(int);

    printf("\n Tamanho de int = %d",tamanho);
    printf("\n");
    return 0;
}