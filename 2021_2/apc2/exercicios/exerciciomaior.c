
#include <stdio.h>
#include <stdlib.h>

void escrever_arquivo(char * nome_arquivo, int numero);

int main()
{
    int i;

    int numero;

    int maior;
    int menor;

    for (i = 0; i < 10; i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d", &numero);

        if (i == 0)
        {
            maior = numero;
            menor = numero;
        }
        else
        {
            if (numero<menor)
            {
                menor = numero;
            }           
            if (numero > maior)
            {
                maior = numero;
            }
        }
    }

    escrever_arquivo("maior.txt",maior);
    escrever_arquivo("menor.txt",menor);
}

void escrever_arquivo(char * nome_arquivo, int numero)
{
    FILE * arq;
    arq = fopen(nome_arquivo,"w");
    if ( arq==NULL)
    {
        printf("\n Problemas na abertura do arquivo");
        return;
    }
    else
    {
        fprintf(arq,"%d",numero);
        fclose(arq);
    }
}