#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome1[30],nome2[30];

    // nome1="Felippe";

    strcpy(nome1,"Felippe");
    // strcpy(nome2,nome1[3]);


    strncpy(nome2,nome1,3);

    // int i;
    // for(i=0;i<3;i++)
    // {
    //     nome2[i] = nome1[i];
    // }
    // nome2[i] = '\0';

    printf("Nome1: %s Nome2: %s",nome1,nome2);

    return 0;

}