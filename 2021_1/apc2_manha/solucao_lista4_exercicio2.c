    // 2) Crie	uma	função que	receba	como	parâmetros	dois	vetores	de
    // inteiros: x1 e x2 e	as suas	respectivas	quantidades	de elementos:n1	e n2.	
    // A função deverá	retornar um	ponteiro para um terceiro vetor, x3, alocado dinamicamente,
    // contendo a união de x1 e x2 e usar o ponteiro  qtd para	retornar o tamanho de x3.	
    // Sendo	
    // x1	=	{1,	3, 5, 6, 7}	e	
    // x2	=	{1,	3, 4, 6, 8},	
    // x3	irá	conter	{1,	3, 4, 5, 6, 7, 8}.
    // Assinatura	da	função:
    // int* uniao(int *x1, int *x2, int n1, int n2, int* qtd);



#include <stdio.h>
#include <stdlib.h>

int* uniao(int *x1, int *x2, int n1, int n2, int* qtd);

int main()
{
    int i;
    int vet1[11] = {1,3,5,6,7,9,10,11,13,15,17};
    int vet2[10] = {1,3,4,6,8,11,12,14,15,16};
    int * vet3,qtd;

    vet3 = uniao(vet1,vet2,11,10,&qtd);

    printf("\nVetor resultante: ");
    for(i=0;i<qtd;i++)
    {
        printf(" %d",vet3[i]);
    }
    free(vet3);

    printf("\n");
    return 0;
}

int* uniao(int *x1, int *x2, int n1, int n2, int* qtd)
{
    int * x3;
    x3 = (int*)calloc(n1+n2,sizeof(int));
    (*qtd)=0;

    int i=0,j=0;

    while(i<n1 && j<n2)
    {
        if (x1[i]==x2[j])
        {
            x3[*qtd] = x1[i];
            i++;
            j++;
            (*qtd)++;
        }
        else
        {
            if (x1[i]<x2[j])
            {
                x3[*qtd] = x1[i];
                i++;
                (*qtd)++;
            }
            else
            {
                x3[*qtd] = x2[j];
                j++;
                (*qtd)++;
            }
        }
    }

    while(i<n1)
    {
        x3[*qtd] = x1[i];
        i++;
        (*qtd)++;
    }

    while(j<n2)
    {
        x3[*qtd] = x2[j];
        j++;
        (*qtd)++;
    }

    return x3;

}

