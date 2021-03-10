#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n");
    int x =2;
    int somatorio;

    mostrar_nome_na_tela();
    mostrar_nome_na_tela2(x);
    x = le_numero_usuario();
    somatorio = le_varios_numeros(5);
    return 0;
}

void mostrar_nome_na_tela()
{
    printf("\n Felippe Giuliani");
}

void mostrar_nome_na_tela2(int x)
{
    int i;
    for (i = 0; i < x; i++)
    {
        printf("\n Felippe Giuliani");
    }
}

int le_numero_usuario()
{
    int x;
    printf("\n Digite um numero: ");
    scanf("%d",&x);

    return x;
}

int le_varios_numeros(int qtd_numeros)
{
    int sum=0,i;
    int x;

    for(i=0;i<qtd_numeros;i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d",&x);
        sum = sum + x;
    }

    return sum;
}

void triplicar(int * x)
{

}



