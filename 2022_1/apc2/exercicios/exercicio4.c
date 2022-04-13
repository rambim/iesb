/*
Elabore uma função que receba três notas de um aluno 
como parâmetro e uma letra. Se a letra for ‘A’, a 
função deve calcular a média aritmética das notas 
do aluno; se a letra for ‘P’, deverá calcular a média 
ponderada, com pesos 5, 3 e 2. Retorne a média 
calculada para o programa principal.

*/

#include <stdio.h>
#include <stdlib.h>

float funcaonome(float n1, float n2, float n3, char letra);

int main()
{
    float media;

    media = funcaonome(2,3,4,'P');
    printf("\n Media calculada: %f",media);
    printf("\n");
    return 0;
}


float funcaonome(float n1, float n2, float n3, char letra)
{
    float media;
    if (letra == 'A')
    {
        media = (n1+n2+n3)/3.0;
    }

    if (letra == 'P')
    {
        media = ((n1*5) + (n2*3) + (n3*2))/10;
    }

    return media;

}