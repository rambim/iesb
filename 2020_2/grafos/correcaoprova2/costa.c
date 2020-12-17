#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct coordenada
{
    int x, y;
} coordenada;

char **aloca_matriz(int l, int c);
void mostrar_matriz(char **m, int l, int c);
int valida_coordenadas(coordenada a, int l, int c);
int conta_costas(char **m, int l, int c);
int main()
{
    int l, c;
    int i, j;

    char **m;
    char *linha;
    int qtd;

    // coordenada a;

    // a.x = 3;
    // a.y = 2;

    // if (valida_coordenadas(a,4,3))
    // {
    //     printf("\n Coordenada valida");
    // }
    // else
    // {
    //     printf("\n Coordenada invalida");
    // }

    // return 0;

    scanf("%d %d", &l, &c);

    linha = (char *)malloc(sizeof(char) * c + 1);

    m = aloca_matriz(l, c);

    for (i = 0; i < l; i++)
    {
        __fpurge(stdin);
        fgets(m[i], c + 1, stdin);
    }

    qtd = conta_costas(m, l,c);

    mostrar_matriz(m, l, c);

    printf("\n Quantidade de costas: %d",qtd);
    return 0;
}

void mostrar_matriz(char **m, int l, int c)
{
    int i, j;
    printf("\n Mostrando a matriz: ");
    for (i = 0; i < l; i++)
    {
        printf("\n");
        for (j = 0; j < c; j++)
        {
            printf("\t%c", m[i][j]);
        }
    }
}

char **aloca_matriz(int l, int c)
{
    char **novo;
    int i;
    novo = (char **)malloc(sizeof(char *) * l);

    for (i = 0; i < l; i++)
    {
        novo[i] = (char *)malloc(sizeof(char) * c);
    }

    return novo;
}

int conta_costas(char **m, int l, int c)
{
    int count = 0;
    int i, j;
    coordenada esq, dir, cima, baixo;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (m[i][j] == '#')
            {
                esq.x = i;
                esq.y = j - 1;
                dir.x = i;
                dir.y = j + 1;
                cima.x = i - 1;
                cima.y = j;
                baixo.x = i + 1;
                baixo.y = j;

                if (valida_coordenadas(esq, l, c))
                {
                    if (m[esq.x][esq.y] == '.')
                    {
                        count++;
                        continue;
                    }
                }
                else
                {
                        count++;
                        continue;
                }
                
                if (valida_coordenadas(dir, l, c))
                {
                    if (m[dir.x][dir.y] == '.')
                    {
                        count++;
                        continue;
                    }

                }
                else
                {
                        count++;
                        continue;
                }
                if (valida_coordenadas(cima, l, c))
                {
                    if (m[cima.x][cima.y] == '.')
                    {
                        count++;
                        continue;
                    }

                }
                else
                {
                        count++;
                        continue;
                }
                if (valida_coordenadas(baixo, l, c))
                {
                    if (m[baixo.x][baixo.y] == '.')
                    {
                        count++;
                        continue;
                    }
                }

            }
        }
    }

    return count;
}

int valida_coordenadas(coordenada a, int l, int c)
{
    if (a.x < 0 || a.x >= l)
    {
        return 0;
    }
    if (a.y < 0 || a.y >= c)
    {
        return 0;
    }
    return 1;
}
