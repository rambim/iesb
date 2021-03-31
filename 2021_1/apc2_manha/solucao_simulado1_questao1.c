// 2. Escreva um procedimento que recebe as 3 notas de um aluno por parâmetro
// e uma letra. Se a letra for A o procedimento calcula a média aritmética das
// notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2) e se for H, a
// sua média harmônica. A média calculada também deve retornar por parâmetro.

#include <stdio.h>
#include <stdlib.h>

float calcula_nota(float n1, float n2, float n3, char tipo);

int main()
{
    printf("\nMedia Aritmética: %f",calcula_nota(1,3,5,'A'));
    printf("\nMedia Ponderada : %f",calcula_nota(1,3,5,'P'));
    printf("\nMedia Harmonica : %f",calcula_nota(1,3,5,'H'));
    printf("\n");
    return 0;
}

float calcula_nota(float n1, float n2, float n3, char tipo)
{
    float media = 0.0;
    switch (tipo)
    {
    case 'A':
        media = (n1 + n2 + n3) / 3.0;
        break;
    case 'P':
        media = (n1 * 5 + n2 * 3 + n3 * 2) / 10.0;
        break;
    case 'H':
        media = 3 / ((1 / n1) + (1 / n2) + (1 / n3));
        break;
    default:
        printf("\n Parametro tipo invalido");
        break;
    }

    return media;
}
