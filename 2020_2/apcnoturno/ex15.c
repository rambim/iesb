#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int tamanho;
    int i;
    char palavra[30]= "FelippeGiuliani";

    tamanho = strlen(palavra);

    printf("\n tamanho = %d",tamanho);

    for(i=0;i<30;i++)
    {
        printf("\nLetra = %c",palavra[i]);
    }

    printf("\n percorrendo segunda vez");
    for(i=0;i<tamanho;i++)
    {
        printf("\nLetra = %c",palavra[i]);
    }

    return 0;

    
    
}