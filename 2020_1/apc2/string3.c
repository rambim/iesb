#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>


int main()
{
    char nome1[30];
    char nome2[30];

    printf("\n Digite o nome 1: ");
    __fpurge(stdin);
    fgets(nome1,30,stdin);

//    nome2 = nome1; // não pode!;

/*
    int i;

    for(i=0;i<strlen(nome1);i++)    não é desnecessário! essa é a forma de se 
                                    percorrer o vetor letra por letra
    {
        nome2[i] = nome1[i];
    }
*/


    strcpy(nome2,nome1);

    printf("\n Nome 1 = %s",nome1);
    printf("\n Nome 2 = %s",nome2);




    return 0;
}


