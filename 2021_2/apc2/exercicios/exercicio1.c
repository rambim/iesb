/*

Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real,
 e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificac¸ao.

*/


#include <stdio.h>
#include <stdlib.h>

void mostrar_conteudo(int a, char b, float c);

int main()
{
    int a = 1;
    char b = 'a';
    float c = 2.5;

    int * ptr_a;
    char * ptr_b;
    float * ptr_c;

    ptr_a = &a;
    ptr_b = &b;
    ptr_c = &c;

    printf("\n Mostrando antes: ");
    mostrar_conteudo(a,b,c);

    *ptr_a = 10;
    *ptr_b = 'b';
    *ptr_c = 100;

    printf("\n Mostrando depois: ");
    mostrar_conteudo(a,b,c);

    printf("\n");
    return 0;
}

void mostrar_conteudo(int a, char b, float c)
{
    printf("\n -> %d",a);
    printf("\n -> %c",b);
    printf("\n -> %f",c);
}