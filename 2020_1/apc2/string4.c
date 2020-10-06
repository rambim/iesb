#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


int main()
{
    char nome1[30];
    char nome2[30];

    printf("\n Digite seu primeiro nome :");
    __fpurge(stdin);
    fgets(nome1,30,stdin);
    nome1[strlen(nome1)-1] = ' ';

    printf("\n Digite seu segundo nome :");
    __fpurge(stdin);
    fgets(nome2,30,stdin);

    //nome2[1] ='.'; exemplo de abreviação!
    //nome2[2] = '\0';

    strcat(nome1,nome2);

    printf("\n Nome 1 : %s",nome1);
    printf("\n Nome 2 : %s",nome2);  



    return 0;

}