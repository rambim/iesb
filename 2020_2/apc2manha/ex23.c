#include <stdio.h>
#include <stdlib.h>

typedef struct teste
{
    int n1,n2,n3;
}teste;


int main()
{
    
    FILE *arq;
    char linha[100];
    char nome[50];
    long int matricula;
    float media;
    arq = fopen("notas.txt", "r");

    if ( arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        // while(fgets(linha,100,arq)!=NULL)
        // {
        //     printf("%s",linha);
        // }

        while(fscanf(arq,"Nome: %s Matricula: %ld Media %f\n", nome, &matricula, &media)!=EOF)
        {
            printf("\n");
            printf("\n Nome lido do arquivo: %s",nome);
            printf("\n Matricula lida      : %ld",matricula);
            printf("\n Media lida          : %f",media);
        }


    }
    return 0;

}