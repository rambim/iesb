#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x = 2, y = 3, z = 4,i,som=0;

    for(i=0;i< x + y + z;i++)
    {
        if (i < 4)
        {
            som = som + ( x + 1);
            som = som + ( y + 2);
            som = som + ( z + 3);
        }
        else
        {
            som = som + ( x + 4);
            som = som + ( y + 5);
            som = som + ( z + 6);
        }
    }
    printf("\n Resultado = %d ", som + x + y + z);
}