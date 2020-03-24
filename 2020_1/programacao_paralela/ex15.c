#include <stdio.h>
#include <stdlib.h>
#define TAM 1000


int main()
{
    int a[TAM], b[TAM], c[TAM];
    int i;

    for(i=0;i<TAM;i++)
    {
        c[i] = a[i] + b[i];
    }

    return 0;
}
