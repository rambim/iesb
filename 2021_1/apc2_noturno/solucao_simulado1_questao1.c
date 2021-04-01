// Escreva um procedimento que recebe as 3 notas de um aluno por parâmetro
// e uma letra. Se a letra for A o procedimento calcula a média aritmética das
// notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2) e se for H, a
// sua média harmônica. A média calculada também deve retornar por parâmetro.

#include <stdio.h>
#include <stdlib.h>

float calcula_media(float n1, float n2, float n3, char tipo);


int main()
{
    float retorno;
    retorno = calcula_media(5.5,6.5,7.5,'A');
    printf("\n Media aritmetica : %f",retorno);
    printf("\n Media Ponderada  : %f",calcula_media(5.5,6.5,7.5,'P'));
    printf("\n Media Harmonica  : %f",calcula_media(5.5,6.5,7.5,'H'));
    printf("\n");
    return 0;
}

float calcula_media(float n1, float n2, float n3, char tipo)
{

    switch (tipo)
    {
    case 'A':
        return (n1 + n2 + n3) / 3.0;
        break;
    case 'P':
        return ((n1 * 5) + (n2 * 3) + (n3 * 2)) / 10.0;
        break;
    case 'H':
        return 3 / ((1 / n1) + (1 / n2) + (1 / n3));
        break;
    default:
        printf("\n Tipo de media informado invalido");
        return 0;
        break;
    }
}
