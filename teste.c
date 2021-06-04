#include <stdio.h>
#include <stdlib.h>

void mostrar_vetor(int * vet ,int tam);

int main()
{

    FILE * arq;
    int * vet, * vet2;
    int tamanho=10;

    vet = (int*)calloc(10,sizeof(int));
    vet2 = (int*)calloc(10,sizeof(int));

    vet[0] = 1;
    vet[3] = 5;
    vet[9] = 7;

    mostrar_vetor(vet,tamanho);

    arq = fopen("base.txt","w");
    if ( arq== NULL)
        return 0;

    fwrite(vet,tamanho,sizeof(int),arq);
    fclose(arq);

    arq = fopen("base.txt","r");

    if ( arq== NULL)
        return 0;
    fread(vet2,tamanho,sizeof(int),arq);
    fclose(arq);

    mostrar_vetor(vet2,tamanho);
    printf("\n");
    return 0;
}

void mostrar_vetor(int * vet ,int tam)
{
    int i;
    printf("\n");
    for(i=0;i<tam;i++)
        printf("%d ",vet[i]);
}