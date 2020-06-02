#include <stdio.h>
#include <stdlib.h>

int * funcao1();

int main()
{
    int * ponteiro;

    ponteiro = funcao1();

    printf("K = %d\n",ponteiro[0]);
    printf("J = %d\n",ponteiro[1]);
    printf("C = %d\n",ponteiro[2]);
    return 0;
}


int *  funcao1()
{
    
    int * vet;
    int k=1, l=2 , c=3;
    vet = (int*)malloc(sizeof(int)*3);

    vet[0] = k;
    vet[1] = l;
    vet[2] = c;

    return vet;

}