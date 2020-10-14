#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#define tam 100000000


typedef struct tabela_dinamica
{
    long int tamanho;
    long int qtd;
    long int * vet;
}tabela_dinamica;


long int * aloca_vetor(long int qtd);
void mostra_vetor(long int * vet , long int qtd);
void copia (long int * vet1, long int  * vet2, long int qtd);
void incluir (tabela_dinamica * tab, long int x);
tabela_dinamica * aloca_tabela();
void remover(tabela_dinamica * tab);

int main()
{
    int i;

    tabela_dinamica * tab1;
    tab1 = aloca_tabela();

    printf("\n inclusoes: ");
    for(i=0;i<50;i++)
    {
        
        incluir(tab1,i+1);
    }    

    printf("\n Remocoes");
    for(i=0;i<50;i++)
    {
        remover(tab1)
    }    
    return 0;

}


tabela_dinamica * aloca_tabela()
{
    tabela_dinamica * novo;
    novo = (tabela_dinamica*)malloc(sizeof(tabela_dinamica));
    novo->qtd =0;
    novo->tamanho=0;
    novo->vet = NULL;
    return novo;
}

void incluir (tabela_dinamica * tab, long int x)
{
        printf("\ninicio %ld / %ld preenchidos",tab->qtd,tab->tamanho);
    long int  * aux=NULL;
    long int i;

    if (tab->tamanho==0)
    {
        tab->vet = (long int *)malloc(sizeof(long int )* 1);
        tab->tamanho = 1;

    }

    if (tab->tamanho == tab->qtd)
    {
        aux = (long int *)malloc(sizeof(long int ) * (2 * tab->tamanho));

        for(i=0;i<tab->qtd;i++)
        {
            aux[i] = tab->vet[i];
        }

        free(tab->vet);
        tab->vet = aux;
        tab->tamanho = tab->tamanho * 2;


    }

    tab->vet[tab->qtd]  = x;
    tab->qtd++;
    printf("\nfinal %ld / %ld preenchidos",tab->qtd,tab->tamanho);
     
}

void remover(tabela_dinamica * tab)
{
        printf("\ninicio %ld / %ld preenchidos",tab->qtd,tab->tamanho);
    long int * aux=NULL;
    long int um_quarto;
    long int i;
    if (tab->qtd ==0)
    {
        printf("\n Tabela vazia");
    }

    printf("\n Removendo % ld ", tab->vet[tab->qtd - 1]);

    tab->vet[tab->qtd - 1] =0;
    tab->qtd--;
    um_quarto = tab->tamanho / 4;

    if (tab->qtd == um_quarto && tab->qtd != 1)
    {
        aux = (long int *)malloc(sizeof(long int ) * (tab->tamanho/2));

        for(i=0;i<tab->qtd;i++)
        {
            aux[i] = tab->vet[i];
        }

        free(tab->vet);
        tab->vet = aux;
        tab->tamanho = tab->tamanho/2;


    }

    printf("\nfinal %ld / %ld preenchidos",tab->qtd,tab->tamanho);

}

long int * aloca_vetor(long int qtd)
{
    int i;
    long int * novo;
    novo = (long int *)malloc(sizeof(long int )* qtd);
    for(i=0;i<qtd;i++)
    {
        novo[i] = 1;
    }

    return novo;
}

void mostra_vetor(long int * vet , long int qtd)
{
    int i;
    for(i=0;i<qtd;i++)
    {
        printf(" %ld",vet[i]);
    }
}

void copia (long int * vet1, long int  * vet2, long int qtd)
{
    int i;
    for(i=0;i<qtd;i++)
    {
        vet2[i] = vet1[i];
    }
}

