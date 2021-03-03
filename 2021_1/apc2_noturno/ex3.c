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

    if (imc < 25 )
    {
        printf("\n Atretico!");
    }
    else
    {
        printf("\n Sobre-peso");
    }
    printf("\n");
    return 0;
}