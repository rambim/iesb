#include <stdio.h>
#include <stdlib.h>

/*
             |
             |
    q2       |       q1
             |
_____________|_________________
             |
             |
    q3       |       q4
             |
             |

Dado um ponto no plano cartesiano representado
por um par de coordenadas (x,y) diga 
em qual quadrante esse ponto se encontra.

ex:  (1,1)   = q1
     (-1,1)  = q2
     (-1,-1) = q3
     (1,-1)  = q4

*/

typedef struct ponto
{
    int x;
    int y;
} ponto;

void preenche_ponto(ponto *a);
void mostra_ponto(ponto a);
int quadrante(ponto a);
void printa(int retorno);

int main()
{
    int retorno;
    ponto a;



    do
    {
    preenche_ponto(&a);
    mostra_ponto(a);
    quadrante(a);

    retorno = quadrante(a);
    printa(retorno);
        
    } while (a.x!=0 || a.y!=0);
    

    return 0;
}

void preenche_ponto(ponto *a)
{
    printf("\n Digite as coordenadas X e Y de um ponto: ");

    // (*a).x eh mesma coisa que a->x;
    // (*a).y eh a mesma coisa que a->y;

    //scanf("%d%d",&(*a).x,&(*a).y);
    scanf("%d%d", &a->x, &a->y);
}

void mostra_ponto(ponto a)
{
    printf("\n Mostrando ponto: ");
    printf("\n X = %d Y = %d", a.x, a.y);
}

int quadrante(ponto a)
{
    /* 1 = 1 quadrante
       2 = 2 quadrante
       3 = 3 quadrante
       4 = 4 quadrante
       5 = sobre o eixo x;
       6 = sobre o eixo y;
       7 = 0,0
    */

    if (a.x > 0 && a.y > 0)
    {
        return 1;
    }
    else
    {
        if (a.x < 0 && a.y > 0)
        {
            return 2;
        }
        else
        {
            if (a.x < 0 && a.y < 0)
            {
                return 3;
            }
            else
            {
                if (a.x > 0 && a.y < 0)
                {
                    return 4;
                }
                else
                {
                    if (a.x == 0 && a.y == 0)
                    {
                        return 7;
                    }
                    else
                    {
                        if (a.x == 0)
                        {
                            return 5;
                        }
                        else
                        {
                            return 6;
                        }
                    }
                }
            }
        }
    }
}

void printa(int retorno)
{
    switch (retorno)
    {
    case 1:
        printf("\n Esta no primeiro quadrante");
        break;
    case 2:
        printf("\n Esta no segundo quadrante");
        break;
    case 3:
        printf("\n Esta no terceiro quadrante");
        break;
    case 4:
        printf("\n Esta no quarto quadrante");
        break;
    case 5:
        printf("\n Esta no eixo x");
        break;
    case 6:
        printf("\n Esta no eixo y");
        break;
    case 7:
        printf("\n esta no ponto 0 0");
        break;
    default:
        printf("\n deu merda");
        break;
    }
}