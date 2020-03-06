#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int numero[20];

    /*

    numero[0] = 1;
    numero[1] = 2;
    numero[2] = 3;
    numero[3] = 4;
    numero[4] = 5;
    */

    for(i=0;i<20;i++)
    {
        numero[i] = i+1;
    }
    
    printf("\n Mostrando o vetor preenchido: ");

    for(i=0;i<20;i++)
    {
        printf("\n %d",numero[i]);
    }
    return 0;
}