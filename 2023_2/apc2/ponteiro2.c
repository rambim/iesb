#include <stdio.h>
#include <stdlib.h>


void mostrar_vetor(int * vet,  int tam);
int main()
{
    int *vet;
    int *ptr2;
    int tam = 3;

    vet = (int*)malloc(sizeof(int)*tam);

    vet[0] = 1;
    vet[1] = 2;
    vet[2] = 3;

    ptr2 = &vet[1];

    // mostrar_vetor(vet,tam);

    printf("%d\n",*ptr2+1);
    printf("%d\n",vet[2]);

    

    return 0;
}


void mostrar_vetor(int * vet,  int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("%d\n",vet[i]);
    }
}

