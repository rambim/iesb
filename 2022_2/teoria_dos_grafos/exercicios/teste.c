#include <stdio.h>
#include <stdlib.h>

typedef struct vertice
{
    int visitado;
    int lista_adj[1000005];
    int tam_lista_adj;
    int cor;
} vertice;

int main()
{
    int vet[1000005];



    int i;

    for(i=0;i<1000005;i++)
    {
        vet[i] = i;
    }

    for(i=0;i<1000005;i++)
    {
        printf(" %d",vet[i]);
    }

    return 0;

}