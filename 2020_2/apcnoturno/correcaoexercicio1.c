#include <stdio.h>
#include <stdlib.h>

typedef struct coordenada
{
    int x,y;    
}coordenada;
void mostrar_quadrante (coordenada x);
void preenche_coordenada ( coordenada * x);

int main()
{
    int i;
    coordenada coordenadas[10];

    // preenche_todas_coordenadas(&coordenadas[0]);
    // preenche_todas_coordenadas(coordenadas);

    for(i=0;i<10;i++)
    {
        preenche_coordenada(&coordenadas[i]);
        mostrar_quadrante(coordenadas[i]);
    }

    printf("\n");
    return 0;
}


void preenche_coordenada ( coordenada * x)
{
    printf("\n Digite a coordenada x: ");
    scanf("%d",&x->x);
    printf("\n Digite a coordenada y: ");
    scanf("%d",&x->y);
}

void preenche_todas_coordenadas(coordenada * x)
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("\n Digite a coordenada x: ");
        scanf("%d",&x[i].x);
        printf("\n Digite a coordenada y: ");
        scanf("%d",&x[i].y);
    }
}

void mostrar_quadrante (coordenada x)
{
    printf("\n Coordenada (X,Y) = (%d,%d)",x.x,x.y);

    if ((x.x==0) && (x.y==0))
    {
        printf("\n Coordenada no ponto neutro ");
    }
    else
    {
        if (x.x==0)
        {
            printf("\n Coordenada no eixo y");
        }
        else
        {
            if (x.y==0)
            {
                printf("\n Coordenada no eixo x");
            }
            else
            {
                if (x.x>0 && x.y>0)
                {
                    printf("\n Coordenada no primeiro quadrante");
                }
                else
                {
                    if (x.x>0 && x.y < 0)
                    {
                        printf("\n Coordenada no quarto quadrante");
                    }
                    else
                    {
                        if (x.x<0 && x.y>0)
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