#include <stdio.h>
#include <stdlib.h>


void mostrar_carta(char simbolo);

int main()
{
    mostrar_carta('2');
    mostrar_carta('7');

    return 0;
}

void mostrar_carta(char simbolo)
{
    printf("\n ___________ ");
    printf("\n|  %c        | ",simbolo);
    printf("\n|           | ");
    printf("\n|           | ");
    printf("\n|           | ");
    printf("\n|           | ");
    printf("\n|           | ");
    printf("\n|___________| ");
}
