#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
    int idade;
    float altura;
}pessoa;

int main()
{
    float a;
    pessoa pessoa1;
    printf("Digite sua altura\n");
    scanf(  "%f" ,&pessoa1);
    printf("Digite sua idade\n");
    scanf("%d",&pessoa1.idade);

    printf("\n A idade da pessoa: %d e sua altura : %f",pessoa1.idade, pessoa1.altura);
    return 0;

}

