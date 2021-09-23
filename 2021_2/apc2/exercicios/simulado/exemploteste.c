#include <stdio.h>
#include <stdlib.h>

int main()
{

    int vet[3];
    
    vet[3000] = 10;

    printf("%d",vet[5]);
  

}


void mostrar( int * vet, int i)
{

    printf("\n %d",vet[i]);
    mostrar(vet,i+1);
}