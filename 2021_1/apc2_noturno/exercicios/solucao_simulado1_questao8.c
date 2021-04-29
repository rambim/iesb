// Escreva uma função que recebe por parâmetro um valor inteiro e positivo N
// e retorna o valor de S.
// S = 2/4 + 5/5 + 10/6 + 17/7 + 26/8 + ... +(n2+1)/(n+3)

// 3 + 5 + 7 + 9 + 11 + 13 + 15

#include <stdio.h>
#include <stdlib.h>



float somatorio(int n);
int main()
{
    int n;
    float s;
    printf("\n Digite o valor de N: ");
    scanf("%d",&n);
    s = somatorio(n);

    printf("\n Somatorio = %f",s);
    
    return 0;    
}

float somatorio(int n)
{
    float numerador;
    float denominador;
    float somatorio=0;
    float limite;
    int i;
    int x;
    
    numerador = 2;
    denominador= 4;
    x = 1;
    limite = n+3;
    printf("\n limite: %f",limite);
    printf("\n Somando: %f / %f",numerador,denominador);
    somatorio = numerador/denominador;
    while(denominador<(n+3))
    {
        x  = x + 2;
        numerador = numerador + x;
        denominador++;
        printf("+ %f / %f",numerador,denominador);
        somatorio = somatorio + (numerador/denominador);
    }
    return somatorio;

}



