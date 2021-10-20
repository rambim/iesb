#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tamanho;
    tamanho = sizeof(int);
    printf("\n int  : %d",tamanho);
    tamanho = sizeof(float);
    printf("\n float: %d",tamanho);
    tamanho = sizeof(char);
    printf("\n char: %d",tamanho);
    tamanho = sizeof(long int );
    printf("\n long int : %d",tamanho);


    printf("\n");
    return 0;
}