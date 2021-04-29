/*
Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificac¸ao.
*/

#include <stdio.h>
#include <stdlib.h>



int main()
{
    int a, *ptr_a;
    float b, *ptr_b;
    char c, *ptr_c;

    a = 2;
    b = 1.5;
    c = 'a';

    ptr_a = &a;
    ptr_b = &b;
    ptr_c = &c;

    printf("\n Conteudo de a antes da mudanca: %d",a);
    printf("\n Conteudo de b antes da mudanca: %f",b);
    printf("\n Conteudo de c antes da mudanca: %c",c);

    *ptr_a = 10;
    *ptr_b = 5.9;
    *ptr_c = 'z';

    printf("\n Conteudo de a depois da mudanca: %d",a);
    printf("\n Conteudo de b depois da mudanca: %f",b);
    printf("\n Conteudo de c depois da mudanca: %c",c);

    return 0;

}




