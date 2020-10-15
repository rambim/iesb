#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coordenada
{
    int x, y;
} coordenada;

void ler_coordenadas(coordenada *vet, int qtd);
void mostrar_coordenadas(coordenada *vet, int qtd);
int quadrante(int x, int y);
void relatorio(coordenada *l1, coordenada *l2);
int maior(int a, int b, int parm);

int main()
{
    coordenada lista1_coordenadas[3];
    coordenada lista2_coordenadas[3];

    ler_coordenadas(lista1_coordenadas, 3);
    ler_coordenadas(lista2_coordenadas, 3);
    printf("\n Mostrando coordenadas da lista 1: ");
    mostrar_coordenadas(lista1_coordenadas, 3);
    printf("\n Mostrando coordenadas da lista 2: ");
    mostrar_coordenadas(lista2_coordenadas, 3);

    relatorio(lista1_coordenadas, lista2_coordenadas);

    printf("\n");
    return 0;
}

void ler_coordenadas(coordenada *vet, int qtd)
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        printf("\n Digite a coordenada no formato X,Y: ");
        scanf("%d,%d", &vet[i].x, &vet[i].y);
    }
}

void mostrar_coordenadas(coordenada *vet, int qtd)
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        printf("\n Coordenada %d = %d , %d  ", i + 1, vet[i].x, vet[i].y);
    }
}

void relatorio(coordenada *l1, coordenada *l2)
{
    int i;
    int qtd[7] = {0};
    int qtd_l1[7] = {0};
    int qtd_l2[7] = {0};
    int maior_indice = 0, maior_qtd = 0;
    int maior_eixo_x;

    for (i = 0; i < 3; i++)
    {
        if (quadrante(l1[i].x, l1[i].y) == -2)
        {
            qtd[6]++;
            qtd_l1[6]++;
        }
        if (quadrante(l1[i].x, l1[i].y) == -1)
        {
            qtd[5]++;
            qtd_l1[5]++;
        }
        if (quadrante(l1[i].x, l1[i].y) == 0)
        {
            qtd[4]++;
            qtd_l1[4]++;
        }
        if (quadrante(l1[i].x, l1[i].y) == 1)
        {
            qtd[0]++;
            qtd_l1[0]++;
        }
        if (quadrante(l1[i].x, l1[i].y) == 2)
        {
            qtd[1]++;
            qtd_l1[1]++;
        }
        if (quadrante(l1[i].x, l1[i].y) == 3)
        {
            qtd[2]++;
            qtd_l1[2]++;
        }
        if (quadrante(l1[i].x, l1[i].y) == 4)
        {
            qtd[3]++;
            qtd_l1[3]++;
        }
        if (quadrante(l2[i].x, l2[i].y) == -2)
        {
            qtd[6]++;
            qtd_l2[6]++;
        }
        if (quadrante(l2[i].x, l2[i].y) == -1)
        {
            qtd[5]++;
            qtd_l2[5]++;
        }
        if (quadrante(l2[i].x, l2[i].y) == 0)
        {
            qtd[4]++;
            qtd_l2[4]++;
        }
        if (quadrante(l2[i].x, l2[i].y) == 1)
        {
            qtd[0]++;
            qtd_l2[0]++;
        }
        if (quadrante(l2[i].x, l2[i].y) == 2)
        {
            qtd[1]++;
            qtd_l2[1]++;
        }
        if (quadrante(l2[i].x, l2[i].y) == 3)
        {
            qtd[2]++;
            qtd_l2[2]++;
        }
        if (quadrante(l2[i].x, l2[i].y) == 4)
        {
            qtd[3]++;
            qtd_l2[3]++;
        }
    }

    for (i = 0; i < 4; i++)
    {
        printf("\nI = %d Qtd[i] = %d", i, qtd[i]);
        if (qtd[i] > maior_qtd)
        {
            maior_qtd = qtd[i];
            maior_indice = i;
        }
    }

    printf("\n O quadrante que possui maior quantidade de ocorrencias e o %d quadrante com %d ocorrencias", maior_indice + 1, qtd[maior_indice]);

    maior(qtd_l1[0], qtd_l2[0], 1);
    maior(qtd_l1[1], qtd_l2[1], 2);
    maior(qtd_l1[2], qtd_l2[2], 3);
    maior(qtd_l1[3], qtd_l2[3], 4);
    maior(qtd_l1[4], qtd_l2[4], 0);
    maior(qtd_l1[5], qtd_l2[5], -1);
    maior(qtd_l1[6], qtd_l2[6], -2);
}

//0   ponto 0
//-1  eixo x;
//-2  eixo y;
// 1 - primeiro quadrante
// 2 - segundo quadrante
// 3 - terceiro quadrante
// 4 - quarto quadrante
int quadrante(int x, int y)
{

    if (x == 0 && y == 0)
        return 0;

    if (y == 0)
        return -1;

    if (x == 0)
        return -2;

    if (x > 0 && y > 0)
        return 1;

    if (x < 0 && y > 0)
        return 2;

    if (x < 0 && y < 0)
        return 3;

    if (x > 0 && y < 0)
        return 4;
}

int maior(int a, int b, int parm)
{
    // printf("\nA= %d B = %d Parm = %d", a, b, parm);
    char texto[30];

    switch (parm)
    {
    case -2:
        strcpy(texto, "eixo y");
        break;
    case -1:
        strcpy(texto, "eixo x");
        break;
    case 0:
        strcpy(texto, "ponto neutro");
        break;
    case 1:
        strcpy(texto, "primeiro quadrante");
        break;
    case 2:
        strcpy(texto, "segundo quadrante");
        break;
    case 3:
        strcpy(texto, "terceiro quadrante");
        break;
    case 4:
        strcpy(texto, "quarto quadrante");
        break;
    }

    if (a > b)
    {
        printf("\n Lista 1 possui maior ocorrencias de %s", texto);
    }
    else
    {
        if (b > a)
        {
            printf("\n Lista 2 possui maior ocorrencias de %s", texto);
        }
        else
        {
            printf("\n Quantidade iguais de ocorrencias no %s", texto);
        }
    }
}