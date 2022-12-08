#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int i;
    do
    {
        scanf("%d", &x);

        if (x != 0)
        {

            for (i = 1; i < x; i++)
            {
                printf("%d ", i);
            }
            printf("%d\n", x);
        }

    } while (x != 0);

    return 0;
}