#include <stdio.h>


int main()
{
    int a=8;
    int b=3;
    int c=-7;
    int teste1 = (a>3) && (b<10) || (c==2);
    int teste2 = (a<b) || (c>1) &&  !(a==5);
    int teste3 = (a%2==0) || (b % 2 ==0) && (c % 2 ==0);

    if (teste1){
        printf("Teste 1 Verdadeiro\n");
    }else
    {
        printf("teste 1 falso\n");
    }

    if (teste2){
        printf("Teste 2 Verdadeiro\n");
    }else
    {
        printf("teste 2 falso\n");
    }
    if (teste3){
        printf("Teste 3 Verdadeiro\n");
    }else
    {
        printf("teste 3 falso\n");
    }

}