#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10


void mostrar_vetor(long long int * vet, long long int tam);
long long int * cria_vetor(long long int tam, int ordenado);

int main()
{
    clock_t start, end;
    long long int i,j,z;

    long long int * vet;

    vet = cria_vetor(TAM,1);
    mostrar_vetor(vet,TAM);
    start = clock();// tempo inicial


    end = clock(); // tempo final;

    printf ( "\ntempo gasto %f milisegundos\n",((double)( end - start ) / 
    ((double)CLOCKS_PER_SEC ))); //impressão do tempo gasto

}


long long int * cria_vetor(long long int tam, int ordenado)
{
    long long int * vet;
    long long int  i;

    vet = (long long int*)malloc(sizeof(long long int)*tam);

    for(i=0;i<tam;i++)
    {
        vet[i] = i + 1;
    }

    return vet;

}

void mostrar_vetor(long long int * vet, long long int tam)
{
    long long int i;
    printf("\n mostrando vetor: ");
    for(i=0;i<tam;i++)
    {
        printf(" %lld",vet[i]);
    }
}