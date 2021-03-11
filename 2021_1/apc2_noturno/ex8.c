#include <stdio.h>
#include <stdlib.h>



int main()
{
    mostrar_nome1();
    int x;

    printf("\n Digite quantas vezes deseja mostrar o numero: ");
    scanf("%d",&x);
    mostrar_nome2(x);

    int y;

    y = le_numero() + 10;

    float total_viagem;

    total_viagem = preco_viagem_disney(10);

}

void mostrar_nome1()
{
    printf("\n Felippe Giuliani");
}

void mostrar_nome2(int * x)
{
    int i;
    for(i=0;i<x;i++)
    {
        printf("\n Felippe Giuliani");
    }

}


int *  le_numero()
{
    int numero;
    printf("\n Digite um numero: ");
    scanf("%d",&numero);

    return numero; 
}

float  preco_viagem_disney(int * qtd_pessoas)
{
    float som=0;
    float valor;
    int i;
    float * ptr;
    ptr = &som;

    for(i=0;i<qtd_pessoas;i++)
    {
        printf("\n Quanto vc precisa em dinheiro: ");
        scanf("%f",&valor);
        som = som + valor;
    }
    return *ptr;
}



