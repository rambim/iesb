// Diga qual será a quantidade de operações realizadas para as seguintes instâncias do problema:

// a) vet[1,2,3,4,5,6,7,8,9,10]
// b) vet[10,20,30,40,50,60,70]
// c) vet[1,3,5,7,9,11,13,15,17]

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,x;
    int vet[]=x; 
    for(i=0;i<sizeof(vet);i++)
    {
        if (vet[i]%3==0)
        {
            for(j=0;j<sizeof(vet);j++)
            {
                printf("\n Senhor");
            }
        }
        else
        {
            printf("\n Gzuz");
        }
    }
}
