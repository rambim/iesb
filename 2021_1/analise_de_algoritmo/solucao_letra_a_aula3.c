#include <stdio.h>
#include <stdlib.h>





int subset(int * vet, int n, int x, int y, int valor);

int main()
{
    int vet[3] = {1,3,5};
    if (subset(vet,4,0,9,7))
        printf("\nTem subsetsum");
    else
        printf("\nNao tem subsetsum");

    printf("\n");
    return 0;
}

int subset(int * vet, int n, int x, int y, int valor)
{
    printf("\n Entrei N= %d X  = %d y = %d Valor = %d",n,x,y,valor);
    if (n==-1)
        return 0;

    if (x + vet[n] == valor)
        return 1;

    // if (x + vet[n] > valor);
    //     return 0;

    return ( subset(vet,n-1,x+vet[n],y-vet[n],valor) || subset(vet,n-1,x,y-vet[n],valor));    

}