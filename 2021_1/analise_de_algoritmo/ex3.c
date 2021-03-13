#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int j = 10;
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

// 1 +  1 + 1 + 1 (5 * IF) + (5 * 2IF)  + 10

// IF = 2
// IF2 = 3

// 1 +  1 + 1 + 1 + (5 * 2) + (5 * 3)  + 10
// 3 + 1+  10 + 15 + 10
// 1 + 15 + 10
// 39