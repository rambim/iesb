#include <stdio.h>
#include <stdlib.h>

typedef struct cachorro
{
    char raca[30];
    float peso;
    int tipo_pelo;
    int idade;
    float tamanho;

}cachorro;


int main()
{
    cachorro * ptr;
    cachorro * ptr2;

    ptr =(cachorro*)malloc(sizeof(cachorro));

    ptr[0].peso = 2;
    ptr->idade = 3;


    ptr2 = (cachorro*)malloc(sizeof(cachorro)*3);

    ptr2[0].peso = 2;
    ptr2[1].tipo_pelo = 3;

    printf("\n");
    return 0;
}