#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int j = N;
    for (i = 0; i < j; i++) 
    {
        if (i % 2 == 0)
        {
            printf("\n Irru");
        }
        else
        {
            printf("\n irru ");
            printf("\n irru ");
        }
    }
}

// 1 + 1 + 1 + 1 + (n * dentro do for) + n
// 4 + (n/2 * 2) + (n/2 * 3) + n
// 4 + n + 3n/2 + n
// 7n/2 + 4
// n + 4
// O(n)


// porem como bem observado, vamos sempre pelo pior caso.

// 4 + (n * 4) + n
// 4 + 4n + n
// 5n + 4;
// O(n)





