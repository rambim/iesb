#include <stdio.h>
#include <stdlib.h>

typedef struct coordenada
{
    int x, y;
} coordenada;

void preenche_coordenada(coordenada *x);
void mostrar_quadrante(coordenada x);

int main()
{

    int i;
    coordenada coordenadas[10];

    
    for (i = 0; i < 10; i++)
    {
        preenche_coordenada(&coordenadas[i]);
        mostrar_quadrante(coordenadas[i]);
    }

    printf("\n");
    return 0;
}

void preenche_coordenada(coordenada *x)
{
    int i;
    printf("\n Digite o ponto X da coordenada: ");
    scanf("%d", &x->x);
    printf("\n Digite o ponto Y da coordenada: ");
    scanf("%d", &x->y);
}

void mostrar_quadrante(coordenada x)
{
    if ((x.x == 0) && (x.y == 0))
    {
        printf("\n Coordenada no ponto neutro");
    }
    else
    {
        if (x.x == 0)
        {
            printf("\n Coordenada sobre o eixo Y");
        }
        else
        {
            if (x.y == 0)
            {
                printf("\n Coordenada sobre eixo X");
            }
            else
            {
                if ((x.x > 0) && (x.y > 0))
                {
                    printf("\n Coordenada no primeiro quadrante");
                }
                else
                {
                    if ((x.x > 0) && (x.y < 0))
                    {
                        printf("\n Coordenada no quarto quadrante");
                    }
                    else
                    {
                        if ((x.x < 0) && (x.y > 0))
                        {
                            printf("\n Coordenada no segundo quadrante");
                        }
                        else
                        {
                            printf("\n Coordenada no terceiro quadrante");
                        }
                    }
                }
            }
        }
    }
}