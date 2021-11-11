#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int x;

    int i;

    for (i = 0; i < 100; i++)
    {
        x = rand() % 100;
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}