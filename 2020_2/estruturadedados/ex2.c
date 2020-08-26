#include <stdio.h>
#include <stdlib.h>

typedef struct registro
{
  int a,b;
    
}registro;


int main()
{   int x;
    char c;

    int tamanho_de_x, tamanho_de_int,tamanho_de_char,tamanho_de_registro;
    tamanho_de_int = sizeof(int);
    tamanho_de_x = sizeof(x);
    tamanho_de_char = sizeof(char);
    tamanho_de_registro = sizeof(registro);
    printf("\n Um inteiro ocupa %d bytes em memoria",tamanho_de_int);
    printf("\n O x ocupa %d bytes em memoria",tamanho_de_x);
    printf("\n Um char ocupa %d bytes em memoria",tamanho_de_char);
    printf("\n Um registro ocupa %d bytes em memoria", tamanho_de_registro);


    printf("\n");
    return 0;

}