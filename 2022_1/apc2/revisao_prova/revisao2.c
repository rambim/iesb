/*
Faça um programa que receba 2 notas do usuario, calcule a média aritmética dessas notas
e mostre na tela se o usuário está aprovado ou reprovado.
Reprovado : entre 0 - 5
Aprovado  : maior que 5 e menor igual a 10.
*/

#include<stdio.h>

int main(){
    float nota1, nota2, notaFinal;

    printf("Insira sua primeira e segunda notas separadas por espaço\n");
    scanf("%f %f", &nota1, &nota2);

    notaFinal = (nota1+nota2)/2;

    if (notaFinal > 5 && notaFinal <= 10){
        printf("Você passou!!\n");
    }else{
        printf("Reprovado, faltou tompêrro\n");
    }

    return 0;
}
