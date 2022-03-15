

/*


Faça um programa em C que receba do usuario o nome de uim arquivo. Cada linha do arquivo é composta por 3 valores
que representam as medidas dos lados de um Triângulo.


Triângulo Isósceles. Tem dois lados iguais e um diferente.
Triângulo Equilátero. Todos os lados são iguais.
Triângulo Escaleno. Nenhum dos lados são iguais.

Exemplo do arquivo:

1;3;3
2;2;2
1;3;4

Mostre na tela quantos triangulos isósceles, equiléteros e esclaenos existem a partir dos valores
presentes dentro do arquivo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int tipo_triangulo(int a, int b, int c);

int main()
{
    char nome_arquivo[50];

    FILE *arq;
    int a, b, c;

    int qtd_tringulos = 0;
    int qtd_1 = 0, qtd_2 = 0, qtd_3 = 0;

    printf("\n Digite o nome do arquivo: ");
    __fpurge(stdin); // fflush(stdin);
    fgets(nome_arquivo, 50, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';

    printf("\n Nome do arquivo lido: %s", nome_arquivo);

    arq = fopen(nome_arquivo, "r");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        while (fscanf(arq, "%d;%d;%d\n", &a, &b, &c) != EOF)
        {
            qtd_tringulos++;
            printf("\n Valores lidos do arquivo: a: %d b: %d c: %d", a, b, c);

            switch (tipo_triangulo(a, b, c))
            {
            case 1:
                qtd_1++;
                break;
            case 2:
                qtd_2++;
                break;
            case 3:
                qtd_3++;
                break;
            default:
                printf("\n retorno invalido");
                break;
            }
        }

        fclose(arq);
    }


    printf("\n Total de triangulos: %d",qtd_tringulos);
    printf("\n Qtd de Isosceles : %d",qtd_1);
    printf("\n Qtd de Equilatero: %d",qtd_2);
    printf("\n Qtd de Escaleno  : %d",qtd_3);

    printf("\n");
    return 0;
}

//1 - Isosceles
//2 - Equilatero
//3 - Escaleno
int tipo_triangulo(int a, int b, int c)
{
    if (a == b && b == c)
    {
        return 2;
    }
    else
    {
        if (a != b && b != c && c != a)
        {
            return 3;
        }
        else
        {
            return 1;
        }
    }
}
