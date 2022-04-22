#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct plano
{
    char nome_plano[100];
    float valor_plano;
} plano;

void preenche_plano(plano *p);
void mostrar_plano(plano p);
void grava_menor(plano a, plano b, plano c);

int main()
{

    plano a, b, c;

    preenche_plano(&a);
    preenche_plano(&b);
    preenche_plano(&c);

    mostrar_plano(a);
    mostrar_plano(b);
    mostrar_plano(c);

    grava_menor(a,b,c);
    printf("\n");
    return 0;
}

void preenche_plano(plano *p)
{
    printf("\n Digite o nome do plano: ");
    __fpurge(stdin); // fflush(stdin) para windows
    fgets(p->nome_plano, 100, stdin);
    p->nome_plano[strlen(p->nome_plano) - 1] = '\0';
    printf("\n Digite o valor do plano: ");
    scanf("%f", & p->   valor_plano);
    // scanf("%f", & (*p). valor_plano);
}

void mostrar_plano(plano p)
{
    printf("\n Nome do plano: %s Valor: %f", p.nome_plano, p.valor_plano);
}

void grava_menor(plano a, plano b, plano c)
{

    FILE *arq;

    arq = fopen("mais_barato.txt", "w");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        if (a.valor_plano <= b.valor_plano && a.valor_plano<= c.valor_plano)
        {
            fprintf(arq, "Nome: %s Valor: %f", a.nome_plano, a.valor_plano);
        }
        else
        {
            if (b.valor_plano <= a.valor_plano && b.valor_plano <= c.valor_plano)
            {
                fprintf(arq, "Nome: %s Valor: %f", b.nome_plano, b.valor_plano);
            }
            else
            {
                fprintf(arq, "Nome: %s Valor: %f", c.nome_plano, c.valor_plano);
            }
        }
    }
}