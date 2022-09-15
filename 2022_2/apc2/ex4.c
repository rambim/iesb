#include <stdio.h>
#include <stdlib.h>


void mostrar_carta(int x);

int main()
{
    int i;


    printf("\na");
    for(i=1;i<=10;i++)
    {
        mostrar_carta(i);
    }
    printf("\nb");
    
    return 0;

}


void mostrar_carta(int x)
{
    printf("\n -----------");
    printf("\n |          |");
    printf("\n |      %d |",x);
    printf("\n |          |" );
    printf("\n |          |");
    printf("\n |          |");
    printf("\n |          |");
    printf("\n |__________|");
}

