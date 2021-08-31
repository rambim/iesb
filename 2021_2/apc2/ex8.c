#include <stdio.h>
#include <stdlib.h>

int main()
{

    int joaozinho_da_silva;
    int avaliacao1=8, avaliacao2=10;

    joaozinho_da_silva = calcula_media_aluno2(avaliacao1,avaliacao2);
    printf("\n Media calculada = %f",joaozinho_da_silva);
    return 0;
}

float calcula_media_aluno2( float a, float b)
{
    return (a+b)/2.0;
}

float calcula_media_aluno()
{
    float n1, n2, media = 0;
    printf("\n Digite a n1: ");
    scanf("%f", &n1);
    printf("\n Digite a n2: ");
    scanf("%f", &n2);
    media = (n1 + n2) / 2.0;
    printf("\n Media do aluno = %f", media);
    return media;
}

