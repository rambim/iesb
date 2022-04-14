/*
Faça um programa que receba do usuário 10 números e mostre na tela o somatório dos números 
pares
*/

#include<stdio.h>

int main(){
    int numeros[10], sum = 0, i;
    
    for(i = 0; i < 10; i++){
        scanf("%d", &numeros[i]);
    }
    for(i = 0; i < 10; i++){
        if(!(numeros[i]%2)){
            sum+= numeros[i];
        }
    }
    
    printf("A somatoria eh %d\n", sum);
    return 0;
}
