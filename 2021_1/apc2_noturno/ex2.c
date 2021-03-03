#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso, altura;
    float imc;

    printf("\nDigite sua altura: ");
    scanf("%f",&altura);
    printf("\nDigite seu peso: ");
    scanf("%f",&peso);

    imc = peso / (altura * altura);

    printf("\n\nIMC = %f",imc);


    return 0;
}