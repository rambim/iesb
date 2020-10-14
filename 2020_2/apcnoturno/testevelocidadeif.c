#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

typedef struct coordenada
{
    int x, y;
} coordenada;
void mostrar_quadrante1(coordenada x);
void mostrar_quadrante2(coordenada x);
void preenche_coordenada(coordenada *x);

int main()
{
    int i, j;
    coordenada coordenadas[10];
    double t1, t2;

    // preenche_todas_coordenadas(&coordenadas[0]);
    // preenche_todas_coordenadas(coordenadas);

    coordenadas[0].x = 1;
    coordenadas[0].y = 1;

    t1 = omp_get_wtime();

    for (i = 0; i < 100000; i++)
    {
        for (j = 0; j < 100000; j++)
        {
            mostrar_quadrante2(coordenadas[0]);
        }
    }
    t2 = omp_get_wtime();
    printf("\n Tempo gasto = %lf", t2 - t1);
    printf("\n");
    return 0;
}

void preenche_coordenada(coordenada *x)
{
    printf("\n Digite a coordenada x: ");
    scanf("%d", &x->x);
    printf("\n Digite a coordenada y: ");
    scanf("%d", &x->y);
}

void preenche_todas_coordenadas(coordenada *x)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\n Digite a coordenada x: ");
        scanf("%d", &x[i].x);
        printf("\n Digite a coordenada y: ");
        scanf("%d", &x[i].y);
    }
}

void mostrar_quadrante1(coordenada x)
{
    // printf("\n Coordenada (X,Y) = (%d,%d)",x.x,x.y);

    if ((x.x == 0) && (x.y == 0))
    {
        x.x = 1;
    }
    else
    {
        if (x.x == 0)
        {
            x.x = 1;
        }
        else
        {
            if (x.y == 0)
            {
                x.x = 1;
            }
            else
            {
                if (x.x > 0 && x.y > 0)
                {
                    x.x = 1;
                }
                else
                {
                    if (x.x > 0 && x.y < 0)
                    {
                        x.x = 1;
                    }
                    else
                    {
                        if (x.x < 0 && x.y > 0)
                        {
                            x.x = 1;
                        }
                        else
                        {
                            x.x = 1;
                        }
                    }
                }
            }
        }
    }
}

void mostrar_quadrante2(coordenada x)
{

    if ((x.x == 0) && (x.y == 0))
    {
        x.x = 1;
    }
    if (x.x == 0 && x.y != 0)
    {
        x.x = 1;
    }
    if (x.y == 0 && x.x != 0)
    {
        x.x = 1;
    }
    if (x.x > 0 && x.y > 0)
    {
        x.x = 1;
    }
    if (x.x > 0 && x.y < 0)
    {
        x.x = 1;
    }
    if (x.x < 0 && x.y > 0)
    {
        x.x = 1;
    }
    if (x.x < 0 && x.y < 0)
    {
        x.x = 1;
    }
}