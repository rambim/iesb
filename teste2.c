#include <stdio.h>
#include <stdlib.h>

void inicializa(int ** mat);
void preenche(int ** mat);
void mostrar_matriz(int **mat );

int main()
{
    int ** mat;

    mat = (int**)malloc(sizeof(int*) * 10);

    int i;

    for(i=0;i<10;i++)
    {
        mat[i] = (int *)malloc(sizeof(int)* 10);
    }

    inicializa(mat);
    preenche(mat);
    mostrar_matriz(mat);
    return 0;
}

void inicializa(int ** mat)
{
    int i=0;
    int j=0;
 

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            mat[i][j] = 0;
        }
    }
}


void preenche(int ** mat)
{
    int i=0;
    int j=0;
    int count = 99;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            mat[i][j] = count--;
        }
    }
}
void mostrar_matriz(int **mat )
{
    int i,j;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}