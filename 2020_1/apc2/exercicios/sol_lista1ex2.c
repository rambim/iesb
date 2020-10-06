#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    float notas[3];
    float media_exercicios;
    float media_aproveitamento;
} aluno;

int main()
{
    aluno a;
    printf("\nDigite a primeira nota do aluno: ");
    scanf("%f", &a.notas[0]);
    printf("\nDigite a segunda nota do aluno: ");
    scanf("%f", &a.notas[1]);
    printf("\nDigite a terceira nota do aluno: ");
    scanf("%f", &a.notas[2]);
    printf("\nDigite a media de exercicios do aluno: ");
    scanf("%f", &a.media_exercicios);

    //MA = (N1 + N2*2 + N3*3 + ME)/7.
    a.media_aproveitamento = (a.notas[0] + (a.notas[1] * 2) + (a.notas[2] * 3) + a.media_exercicios) / 7.0;

    printf("\nMedia de Aproveitamento: %f",a.media_aproveitamento);
    if (a.media_aproveitamento >= 9)
    {
        printf("\nFINAL = A");
    }
    else
    {
        if (a.media_aproveitamento >= 7.5)
        {

            printf("\nFINAL = B");
        }
        else
        {
            if (a.media_aproveitamento >= 6)
            {
                printf("\nFINAL = C");
            }
            else
            {
                if (a.media_aproveitamento >= 4)
                {
                    printf("\nFINAL = D");
                }
                else
                {
                    printf("\nFINAL = E");
                }
            }
        }
    }

    printf("\n");

    return 0;
}
