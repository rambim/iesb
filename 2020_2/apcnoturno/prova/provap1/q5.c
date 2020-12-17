#include <stdio.h>
#include <stdlib.h>

typedef struct coordenada
{
    int x, y;

} coordenada;
void preenche_coordenaadas(coordenada *vet, int qtd);
int quadrante(coordenada c);
void relatorio(coordenada *l1, coordenada *l2);
char *texto_quadrante(int i);

int main()
{
    coordenada lista1_coordenadas[3];
    coordenada lista2_coordenadas[3];

    preenche_coordenaadas(lista1_coordenadas, 3);
    preenche_coordenaadas(lista2_coordenadas, 3);

    relatorio(lista1_coordenadas, lista2_coordenadas);

    printf("\n");
    return 0;
}

void preenche_coordenaadas(coordenada *vet, int qtd)
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        printf("\nDigite a coordenada no formato X,Y: ");
        scanf("%d,%d", &vet[i].x, &vet[i].y);
    }
}

void relatorio(coordenada *l1, coordenada *l2)
{
    int qtd_l1[7] = {0}, qtd_l2[7] = {0}, qtd[7] = {0};
    int i;
    int maior_conteudo = 0, maior_indice = 0;

    for (i = 0; i < 3; i++)
    {
        qtd[quadrante(l1[i])]++;
        qtd[quadrante(l2[i])]++;

        qtd_l1[quadrante(l1[i])]++;
        qtd_l2[quadrante(l2[i])]++;
    }

    for (i = 0; i < 7; i++)
    {
        if (qtd[i] > maior_conteudo)
        {
            maior_conteudo = qtd[i];
            maior_indice = i;
        }
    }

    printf("\n Maior indice = %d", maior_indice);
    printf("\n O quadrante com maior numero de ocorrencias e o %s com %d ocorrencias", texto_quadrante(maior_indice), qtd[maior_indice]);

    for (i = 0; i < 7; i++)
    {
        if (qtd_l1[i] > qtd_l2[i])
        {
            printf("\nLista 1 possui mais elementos no %s", texto_quadrante(i));
        }
        else
        {
            if (qtd_l1[i] < qtd_l2[i])
            {
                printf("\nLista 2 possui mais elementos no %s", texto_quadrante(i));
            }
            else
            {
                printf("\nLista 1 possui a mesma quantidade que a Lista 2 no %s",texto_quadrante(i));
            }
            
        }
    }
}

int quadrante(coordenada c)
{
    if (c.x > 0 && c.y > 0)
        return 1;
    if (c.x < 0 && c.y > 0)
        return 2;
    if (c.x < 0 && c.y < 0)
        return 3;
    if (c.x > 0 && c.y < 0)
        return 4;
    if (c.x == 0 && c.y == 0)
        return 0;
    if (c.y == 0 && c.x != 0)
        return 5;
    if (c.x == 0 && c.y != 0)
        return 6;
}

char *texto_quadrante(int i)
{
    switch (i)
    {
    case 0:
        return "quadrante neutro";
        break;
    case 1:
        return "primeiro quadrante";
        break;
    case 2:
        return "segundo quadrante";
        break;
    case 3:
        return "terceiro quadrante";
        break;
    case 4:
        return "quarto quadrante";
        break;
    case 5:
        return "eixo x";
        break;
    case 6:
        return "eixo y";
        break;
    }
}

