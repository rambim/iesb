/*


 Faça um programa que receba do usuário sua idade e mostre na tela se a idade é um numero par
 ou é um número ímpar.
 

*/


#include <stdio.h>
#include <stdlib.h>

int main()
{

    int idade;

    printf("\n Digite sua idade: ");
    scanf("%d",&idade);

    if (idade%2==0)
    {
        printf("\n idade e par");
    }
    else
    {
        printf("\n Idade e impar");
    }

    printf("\n");
    return 0;
}



