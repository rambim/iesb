#include <stdio.h>
#include <stdlib.h>
void preencher_vetor(float * vet, int tam);
void mostrar_menores_que_10(float * vet , int tam);

int main()
{
    float vet[100], tam = 100;

    preencher_vetor(vet,100);
    return 0;
}

void preencher_vetor(float * vet, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        scanf("%d",&vet[i]);
    }
}

void mostrar_menores_que_10(float * vet , int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if (vet[i]<10)
        {
            printf("A[%d] = %.1f\n",vet[i]);
        }
    }
}