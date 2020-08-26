#include <stdio.h>
#include <stdlib.h>

typedef struct par
{
    int x,y;

}par;

void monta_matriz(par *vetor, int n);

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
    return 0;
}


void monta_matriz(par *vetor, int n)
{
    //if n = 10, matriz com 21
    int matriz[21][21];
    // for(i=0;i<10;i++)
    // {


    // }


}