#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n");
    return 0;
}



void insertion_sort(int * vet, int tam)
{
    int i,j,aux;

    //   1  + 1 + n + n + n(for1)
    for(i=1;i<tam;i++)
    {
        aux = vet[i]; //1
        for(j=i-1;j>=0 && aux<vet[j];j--)  // 1 + 1 + n + n + n*(for2)
        {
            vet[j+1] = vet[j]; // 1
        }
        vet[j+1] = aux; // 1
    }
    return; // 1
}

//   1 + 1 + n + n + n(for1)
// for1 = 4 + 2n + n*(for2) 
// for2 = 1;
// 2 + 2n + n(4 + 2n + n)
// 2 + 2n + n(4 + 3n)
// 2 + 2n + 4n + 3n²
// 2 + 6n + 3n²
// O(n²)








