#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct triangulo
{
    int lado1;
    int lado2;
    int lado3;
} triangulo;

int verifica_tipo_tringulo(triangulo a);

int main()
{
    char nome_arquivo[50];
    int retorno;
    triangulo a;
    FILE *arq;
    int qtd_linhas = 0;

    printf("\nDigite o nome do arquivo: ");
    __fpurge(stdin);
    fgets(nome_arquivo, 48, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';

    arq = fopen(nome_arquivo, "r");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        while (fscanf(arq, "%d;%d;%d\n", &a.lado1, &a.lado2, &a.lado3) != EOF)
        {
            qtd_linhas++;
            printf("\n Linha %d Lado1: %d Lado2: %d Lado 3: %d", qtd_linhas, a.lado1, a.lado2, a.lado3);

            retorno = verifica_tipo_tringulo(a);

            switch (retorno)
            {
            case 1:
                printf("\tTriangulo Equilatero");
                break;
            case 2:
                printf("\tTriangulo escaleno");
                break;
            case 3:
                printf("\tTriangulo isosceles");
                break;
            default:
                printf("\t Retorno invalido");
                break;
            }
        }
        fclose(arq);
    }

    printf("\n");
    return 0;
}

//1 - equilatero
//2 - escaleno
//3 - isosceles

int verifica_tipo_tringulo(triangulo a)
{
    if (a.lado1 == a.lado2 && a.lado2 == a.lado3)
    {
        return 1;
    }
    else
    {
        if (a.lado1 != a.lado2 && a.lado2 != a.lado3 && a.lado3 != a.lado1)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}
