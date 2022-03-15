#include <stdio.h>
#include <stdlib.h>

typedef struct teste
{
    int vet[1000];
}teste;


int main()
{
    printf("\n tamanho: %ld",sizeof(teste));
    return 0;
}