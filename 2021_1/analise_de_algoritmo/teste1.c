#include <stdio.h>
#include <stdlib.h>

int ** aloca_matriz(int l, int c);
void mostrar_m(int ** m, int l, int c);


int main()
{
    int **m;

    int l = 10;
    int c = 10;
    m = aloca_matriz(l,c);
    mostrar_m(m,l,c);
    printf("\n");
    return 0;
}


int ** aloca_matriz(int l, int c)
{
    int ** m;
    int i;
    m = (int**)calloc(l,sizeof(int*));

    for(i=0;i<l;i++)
    {
        m[i] = (int*)calloc(c,sizeof(int));
    }

    return m;
}

void mostrar_m(int ** m, int l, int c)
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