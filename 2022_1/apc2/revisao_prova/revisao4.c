/*
Faça um programa que receba 10 números do usuário e mostre na tela quantos e quais são primos
*/
#include<stdio.h>

int main(){
    int numeros[10]; //valores
    int quantosPrimo, i, j, divs;
    
    quantosPrimo = 0;
  
    for(i = 0; i < 10; i++){
        scanf("%d", &numeros[i]);
    }
    for(i = 0; i < 10; i++){
        divs = 0;
        for(j = 2; j <= numeros[i]; j++){
            if(numeros[i] == 1){
                quantosPrimo++;
                printf("1 eh primo\n");
                break;
            }
            if(numeros[i]%j == 0){
                divs++;
            }
        }
        if (divs <= 1){
            quantosPrimo++;
            printf("%d eh primo\n", numeros[i]);
        }
    }
    printf("Ao todo, %d numeros sao primos\n", quantosPrimo);
    return 0;
}
