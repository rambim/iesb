#include <stdio.h>
#include <stdlib.h>

void mostra_vetor(int * vet, int tam);
void dobrar1(int x);
void dobrar_vetor(int * vet, int tam);

int main()
{
    int x = 2;
    int vet[10]={1,2,3,4,5,6,7,8,9,10};

    printf("\n vet     -> %d",vet);
    printf("\n indice 0-> %d", &vet[0]);
    printf("\n indice 1-> %d",&vet[1]);
    


/*
    dobrar1(x);
    printf("\n %d",x);

    dobrar_vetor(vet,10);

    mostra_vetor(vet,10);

*/
}

void dobrar1(int x)
{
    x = x*2;
}

void dobrar_vetor(int * vet, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        vet[i] = vet[i] * 2;
    }
}

void mostra_vetor(int * vet, int tam)
{
    int i;
    printf("\n Mostrando o vetor");
    for(i=0;i<tam;i++)
    {
        printf("\n%d",vet[i]);
    }

}