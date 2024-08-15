//escreva uma função que calcule e retorne 
//a distância entre dois pontos (x1, y1) e (x2, y2). 
//Todos os números e valores de retorno devem ser do
//tipo float

// D = RAIZ((x2 - x1)² + (y2-y1)²)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcula_distancia(float x1, float y1, float x2, float y2);
int main()
{
    float x1,x2,y1,y2;
    float distancia;

    printf("Digite o valor de X1 e Y1: ");
    scanf("%f %f",&x1,&y1);

    printf("Digite o valor de X2 e Y2: ");
    scanf("%f %f",&x2,&y2);


    distancia = calcula_distancia(x1,y1,x2,y2);

    printf("A distancia entre os 2 pontos = %f",distancia);

    return 0;
}

float calcula_distancia(float x1, float y1, float x2, float y2)
{
    float distancia;
    distancia = sqrt(((x2 - x1) * (x2 - x1)) + ((y2-y1) * (y2-y1)));
    return distancia;
}

