#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct registro
{
    int valor1;
    int valor2;
   
   
}registro;


void mostrar_struct(registro x);

int main()
{
    registro a;
    a.valor1 = 2;
    a.valor2 = 3;
    
    mostrar_struct(a);

    printf("\n DIgite um valor 1 : ");
    scanf("%d",&a.valor1);
    printf("\n Digite um valor 2 : ");
    scanf("%d",&a.valor2);
    
    
    mostrar_struct(a);

    registro * b;

    b = (registro*)malloc(sizeof(registro));

    (*b).valor1 = 2;
    b->valor2 = 3;

    mostrar_struct(*b);

    registro * c;

    c = (registro*)malloc(sizeof(registro)*3);

    c[0].valor1 = 1;
    c[0].valor2 = 1;
    c[1].valor1 = 2;
    c[1].valor2 = 2;
    c[2].valor1 = 3;
    c[2].valor2 = 3;

    mostrar_struct(c[0]);
    mostrar_struct(c[1]);
    mostrar_struct(c[2]);


    printf("\n");
}

void mostrar_struct(registro x)
{
    printf("\n Mostrando a struct: ");
    printf("\n Valor = %d",x.valor1);
    printf("\n Valor 2 = %d",x.valor2);
    
    printf("\n");
}

