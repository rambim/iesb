// 15. Escreva um procedimento que recebes 3 valores reais X, Y e Z e que
// verifique se esses valores podem ser os comprimentos dos lados de um
// triângulo e, neste caso, retornar qual o tipo de triângulo formado. Para que X, Y
// e Z formem um triângulo é necessário que a seguinte propriedade seja
// satisfeita: o comprimento de cada lado de um triângulo é menor do que a soma
// do comprimento dos outros dois lados. O procedimento deve identificar o tipo
// de triângulo formado observando as seguintes definições:

// o Triângulo Equilátero: os comprimentos dos 3 lados são iguais.
// o Triângulo Isósceles: os comprimentos de 2 lados são iguais.
// o Triângulo Escaleno: os comprimentos dos 3 lados são diferentes.

#include <stdio.h>
#include <stdlib.h>

int valida_trinangulo(double x, double y, double z);

int main()
{
    double l1, l2, l3;

    printf("\n Digite o tamanho do lado 1: ");
    scanf("%lf", &l1);
    printf("\n Digite o tamanho do lado 2: ");
    scanf("%lf", &l2);
    printf("\n Digite o tamanho do lado 1: ");
    scanf("%lf", &l3);

    switch (valida_trinangulo(l1, l2, l3))
    {
    case 0:
        printf("\n Nao pode ser um triangulo");
        break;
    case 1:
        printf("\n Triangulo equilatero");
        break;
    case 2:
        printf("\n Triangulo Isosceles");
        break;
    case 3:
        printf("\n Triangulo Escaleno");
        break;
    default:
        printf("\n Retorno da funcao nao previsto");
        break;
    }

    return 0;
}

/*
0 - não for um triangulo
1 - Equilatero
2 - Isosceles
3 - Escaleno
*/

int valida_trinangulo(double x, double y, double z)
{
    if ((x < y + z) && (y < x + z) && (z < x + y))
    {
        if (x == y && y == z)
            return 1;
        else
        {
            if (x != y && y != z && z!=x)
            {
                return 3;
            }
            else
            {
                return 2;
            }
        }
    }
    else
    {
        return 0;
    }
}
