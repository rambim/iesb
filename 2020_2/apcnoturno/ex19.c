#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funcao(int * vet);
int main()
{
    int tamanho;
   
    tamanho = sizeof(int);
    printf("\n O tamanho de int.........  = %d",tamanho);

    tamanho = sizeof(float);
    printf("\n O tamanho de float.......  = %d",tamanho);

    tamanho = sizeof(char);
    printf("\n O tamanho de char......... = %d",tamanho);

    tamanho = sizeof(long int);
    printf("\n O tamanho de long int..... = %d",tamanho);

    tamanho = sizeof(long long int);
    printf("\n O tamanho de long long int = %d",tamanho);

    printf("\n");
    return 0;
}
