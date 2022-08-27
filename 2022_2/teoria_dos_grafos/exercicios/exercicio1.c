/*
Faça um programa que receba do usuário N pares de valores, onde cada PAR representa uma aresta
bidirecional entre cada valor do par.

Mostre uma matriz de adjacência que represente esse grafo
Mostre uma lista de adjacência que represente esse grafo.

1 2
1 4
2 5
3 6

*/


#include <stdio.h>
#include <stdlib.h>

void mostrar_matriz(int ** mat, int l , int c);

int main()
{

    int **mat;
    int i;

    mat = (int**)malloc(sizeof(int*)*50);
    for(i=0;i<50;i++)
    {
        mat[i] = (int*)malloc(sizeof(int)*50);
    }


    mostrar_matriz(mat,3,3);
    return 0;
}


void mostrar_matriz(int **mat, int l , int c)
{
    int i,j;

    for(i=0;i<l;i++)
    {
        
        for(j=0;j<c;j++)
        {
            printf("\t%d",mat[i][j]);
        }
        printf("\n");
    }
}