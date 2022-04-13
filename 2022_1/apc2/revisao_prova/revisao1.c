/*


 Faça um programa que receba do usuário sua idade e mostre na tela se a idade é um numero par
 ou é um número ímpar.
 

*/

#include<stdio.h>

int main(){
    int idade;

    scanf("%d", &idade);

    if (idade%2 == 0){
        printf("A sua idade é par\n");
    }else{
        printf("A sua idade é impar\n");
    }

    return 0;
}
