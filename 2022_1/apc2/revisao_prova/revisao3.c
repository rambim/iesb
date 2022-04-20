/*


Faça um programa que receba do usuário 10 números
e mostre na tela qual foi o maior e o menor número digitado.

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numeros[10];
    int i;
    int maior,menor;

    for(i=0;i<10;i++)
    {
        printf("\n Digite um numero: ");
        scanf("%d",&numeros[i]);

        if (i==0)
        {
            maior = numeros[i];
            menor = numeros[i];
        }
        else
        {
            if (numeros[i] > maior)
            {
                maior = numeros[i];
            }

            if (numeros[i] < menor)
            {
                menor = numeros[i];
            }
        }
    }

    printf("\n Maior numero : %d",maior);
    printf("\n Menor numero: %d",menor);

    printf("\n");
    return 0;
}