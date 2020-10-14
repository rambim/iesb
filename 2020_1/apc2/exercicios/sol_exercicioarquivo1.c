#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    FILE * arq;

    do
    {
        printf("\n Digite N: ");
        scanf("%d",&n);
    } while (n<=0);

    arq = fopen("resposta.txt","w");

    if ( arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        fprintf(arq,"%d",n*2);
        fclose(arq);
    }

    return 0;    


    
    return 0;
}