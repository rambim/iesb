#include <stdio.h>
#include <stdlib.h>

void mostrar (int ** m , int l , int c);
int ** aloca_matriz(int l , int c);
int main()
{

    int ** m;
    int l=20;
    int c=30;
    m = aloca_matriz(l,c);
    mostrar(m,l,c);


    printf("\n");
    return 0;
}

int ** aloca_matriz(int l , int c)
{
    int ** m;
    int i;
    m =(int**)calloc(l,sizeof(int*));

    for(i=0;i<l;i++)
    {
        m[i] = (int*)calloc(c,sizeof(int));
    }

    return m;
}

void mostrar (int ** m , int l , int c)
{
    int i,j;

    for(i=0;i<l;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        {
            printf("\t%d",m[i][j]);
        }
    }
}
