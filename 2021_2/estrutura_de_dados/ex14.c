#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int iguais(int x, int y);
int busca_sequencial(int * vet, int tam , int x);
int busca_binaria(int * vet, int inicio, int fim, int x);

int main()
{
    int * vet;
    int tam=1000000;

    vet =(int*)calloc(tam,sizeof(tam));

    clock_t t; //variável para armazenar tempo

    t = clock(); //armazena tempo
    
    // busca_sequencial(vet,tam,83);
    busca_binaria(vet,0,tam-1,83);

    t = clock() - t; //tempo final - tempo inicial

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC))); 



    printf("\n");
    return 0;
}

int busca_sequencial(int * vet, int tam , int x)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if (iguais(vet[i],x))
            return 1;
    }

    return 0;

}

int iguais(int x, int y)
{
    int i,j;
    int aux;

    for(i=0;i<100;i++)
    {
        for(j=0;j<1000;j++)
        {
            aux = 1;
        }
    }

    if (x == y)
        return 1;
    else
        return 0;
}

int busca_binaria(int * vet, int inicio, int fim, int x)
{

    if (inicio>fim)
        return 0;

    int meio;
    meio = (inicio + fim) /2;

    if (iguais(vet[meio],x))
    {
        return 1;
    }
    else
    {
        if (x > vet[meio])
        {
            busca_binaria(vet,meio+1,fim,x);
        }
        else
        {
            busca_binaria(vet,inicio,meio-1,x);
        }
    }
}