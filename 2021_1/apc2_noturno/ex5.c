#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso, altura;
    float imc;
    int qtd = 10,  i;

    for (i = 0; i < qtd; i++)
    {
        printf("\nDigite sua altura: ");
        scanf("%f", &altura);
        printf("\nDigite seu peso: ");
        scanf("%f", &peso);

        imc = peso / (altura * altura);

        printf("\n\nIMC = %f", imc);

        if (imc < 25)
        {
            printf("\n Atretico!");
        }
        else
        {
            printf("\n Sobre-peso");
        }
    }

    printf("\n");
    return 0;
}