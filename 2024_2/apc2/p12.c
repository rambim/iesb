#include <stdio.h>

int main()
{
    int numeros[] = {-1,2,-3,4,5,-6,7,-8,9,10};
    int resultado;

    for(int i  =0; i<10 ;i++)
    {
        if (i%2!=0)
        {
            resultado += numeros[i] * numeros[i] * -1;
        }
        else
        {
            resultado -= numeros[i];
        }
    }

    printf("\n Resultado = %d",resultado);
}