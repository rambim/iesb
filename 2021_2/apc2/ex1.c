#include <stdio.h>
#include <stdlib.h>


int main()
{
    float peso;
    float altura;
    float imc;

    printf("\nDigite o seu peso: ");
    scanf("%f",&peso);
    printf("\nDigite o sua altura: ");
    scanf("%f",&altura);
    imc = peso/(altura*altura);
    altura=0;
    peso=0;
    printf("O IMC calculado e igual a %f ",imc);
    printf("\n");
    return 0;

    


}
