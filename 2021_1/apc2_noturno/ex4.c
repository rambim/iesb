#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*
    1 - brasil
    2 - argentina
    3 - mexico
    4 - usa
    */

    int pais_do_candidato = 1;

    if (pais_do_candidato == 1)
    {
        printf("\n Brasil");
    }
    else
    {
        if (pais_do_candidato == 2)
        {
            printf("\n Argentina");
        }
        else
        {
            if (pais_do_candidato == 3)
            {
                printf("\n mexico");
            }
            else
            {
                if (pais_do_candidato == 4)
                {
                    printf("\n usa");
                }
            }
        }
    }

    printf("\n");
    return 0;
}