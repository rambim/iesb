#include <stdio.h>
#include <stdlib.h>


int main()
{
    int * vet;
    char * vet2;
    float * vet3;

    vet  = (int *) malloc(4 *5);
    vet2 = (char*) malloc(1*20);
    vet3 = (float*)malloc(4*5);


    return 0;
}