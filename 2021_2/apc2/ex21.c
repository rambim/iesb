#include <stdio.h>
#include <stdlib.h>

typedef struct produto
{
    int codigo;
    float valor;
    int qtd;
    char a,b,c,d,e,f,g,h,i;
    int teste;

} produto;

produto preenche_produto();
void mostrar_produto(produto a);

int main()
{
    printf("\n Bytes de um produto: %ld",sizeof(produto));
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