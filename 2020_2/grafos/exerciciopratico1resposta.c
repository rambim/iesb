#include <stdio.h>
#include <stdllib.h>

typedef struct par
{
    int x,y;

}par;

int main()
{
    int n,i;

    par * vetor;

    printf("\n Digite o valor de N: ");
    scanf("%d",&n);

    vetor = (par*)malloc(sizeof(par)*n);

    for(i=0;i<n;i++)
    {
        scanf("%d;%d",&vetor->x,&vetor->y);
    }






}


void monta_matriz(par *vetor, int n)
{
    //if n = 10, matriz com 21
    int matriz[21][21];
    for(i=0;i<10;i++)
    {


    }


}