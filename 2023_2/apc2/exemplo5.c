#include <stdio.h> #include <stdlib.h>
int main()
{
    int x = 2, y = 3;
    if ((x > 1) && (y < 3))
        printf("b");
    else
    {
        if (x + y == 10)
        {
            printf("c");
        }
    }
    return 0;
}