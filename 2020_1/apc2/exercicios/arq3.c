#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    char letra;
    char linha[500];

    arq = fopen("arquivoteste.txt", "r");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        
        while(fgets(linha,500,arq)!=NULL)
        {
            
            printf("%s",linha);            
        }

        fclose(arq);
    }

    return 0;
}