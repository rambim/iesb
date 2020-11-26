#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int comeca_com_b(char * linha);

int main()
{
    FILE * arq;
    char linha[100];
    int count=0;

    arq = fopen("nomes.txt","r");
    if ( arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
        return 0;
    }

    while(fgets(linha,100,arq)!=NULL)
    {
       if (comeca_com_b(linha))
       {
           count++;
       } 
    }
    fclose(arq);

    printf("\nExistem %d nomes com a inicial B",count);
    printf("\n");
    return 0;
}

int comeca_com_b(char * linha)
{
    if (linha[0] == 'b' || linha[0] == 'B')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}