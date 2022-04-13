/*
Faça um programa que receba do usuário 10 números
e mostre na tela qual foi o maior e o menor número digitado.
*/

#include<stdio.h>

int main(){
    int numerosEscolhidos[10], maiorNumero, menorNumero, index;
    
    for (index = 0; index < 10; index++){
        scanf("%d", &numerosEscolhidos[index]);
    }
    menorNumero = numerosEscolhidos[0];
    maiorNumero = numerosEscolhidos[0];
    for(index = 1; index < 10; index++){
        if (numerosEscolhidos[index] > maiorNumero){
            maiorNumero = numerosEscolhidos[index];
        }
        if (numerosEscolhidos[index] < menorNumero){
            menorNumero = numerosEscolhidos[index];
        }
    }
    
    printf("%d eh o maior numero\n%d eh o menor numero\n", maiorNumero, menorNumero);
    return 0;
}
