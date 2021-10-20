#include <stdio.h>
#include <stdlib.h>

typedef struct produto
{
    int codigo;
    float valor;
    int qtd;
} produto;

produto preenche_produto();
void mostrar_produto(produto a);

int main()
{
    int a;
    int * b;

    a = 2;
    b = &a;

    printf("\n Conteudo de a: %d",a);
    printf("\n Conteudo de a: %d",*b);

    produto c;
    produto *d;

    c = preenche_produto();
    d = &c;

    printf("\n Codigo : %d",c.codigo);
    printf("\n Codigo : %d",(*d).codigo);
    printf("\n Codigo : %d",d->codigo);

}

produto preenche_produto()
{
    produto aux;
    printf("\n Digite o codigo do produto: ");
    scanf("%d", &aux.codigo);
    printf("\n Digite o valor do produto: ");
    scanf("%f", &aux.valor);
    printf("\n Digite a quantidade em estoque do produto: ");
    scanf("%d", &aux.qtd);

    return aux;
}

void mostrar_produto(produto a)
{
    printf("\n Codigo: %d", a.codigo);
    printf("\n Valor: %f", a.valor);
    printf("\n Qtd: %d", a.qtd);
}