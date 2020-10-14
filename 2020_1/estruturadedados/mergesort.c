#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "omp.h"
void mergesort(long int v[], long int inicio, long int fim);
void intercala(long int v[], long int inicio, long int meio, long int fim);
void mostrar_vetor(long int * vet , long int qtd);
long int * aloca_vetor_randomico(long int qtd);

void mergesort(long int v[], long int inicio, long int fim)
{
    long int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim) /2;
        mergesort(v, inicio, meio);
        mergesort(v, meio + 1, fim);
        intercala(v, inicio, meio, fim);
    }
    return;
}
void intercala(long int v[], long int inicio, long int meio, long int fim)
{ /* intercalação no vetor temporário auxiliar */
    long int i, j, k, *auxiliar;
    auxiliar = (long int *)calloc(sizeof(long int), fim - inicio + 1);
    i = inicio;
    j = meio + 1;
    k = 0;
    while (i <= meio && j <= fim)
    {
        if (v[i] <= v[j])
        {
            auxiliar[k] = v[i];
            i++;
        }
        else
        {
            auxiliar[k] = v[j];
            j++;
        }
        k++;
    }
    while (i <= meio)
    {
        auxiliar[k] = v[i];
        i++;
        k++;
    }
    while (j <= fim)
    {
        auxiliar[k] = v[j];
        j++;
        k++;
    }
    for (i = 0; i < (fim - inicio) + 1; i++)
    {
        v[inicio + i] = auxiliar[i];
    }
    free(auxiliar);
    return;
}
int main(void)
{

    long int * vet;
    long int tam;
    double t1,t2;
    printf("\n Digite o tamanho do vetor: ");
    scanf("%ld",&tam);

    t1 = omp_get_wtime();
    vet = aloca_vetor_randomico(tam);
    t2 = omp_get_wtime();

    printf("\n Tempo para criar vetor: %lf",t2-t1);
    
    t1 = omp_get_wtime();
    mergesort(vet,0,tam-1);
    t2 = omp_get_wtime();

    printf("\n Tempo Mergesort: %lf",t2-t1);

    printf("\n");
   // mostrar_vetor(vet,tam);
   printf("\n");

    return 0;
}

void mostrar_vetor(long int * vet , long int qtd)
{
    long int i;
    for(i=0;i<qtd;i++)
    {
        printf(" %ld",vet[i]);
    }
}


long int * aloca_vetor_randomico(long int qtd)
{
    long int * vetor;
    long int i;
    long int i_aux, aux;
    vetor = (long int*)malloc(sizeof(long int)*qtd);

    for(i=0;i<qtd;i++)
    {
        vetor[i] = i+1;
    }
    srand(time(NULL));

    for(i=0;i<qtd;i++)
    {
        i_aux = rand() % qtd;
        aux = vetor[i];
        vetor[i] = vetor[i_aux];
        vetor[i_aux] = aux;

    }

    return vetor;
}