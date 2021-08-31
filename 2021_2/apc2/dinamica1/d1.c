#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 5;
    int y = 3;
    int z = x * 4;

    if (x > 4) {
        printf("\nA");
        if (z < 15) {
            printf("\nB");
        }
        else {
            printf("\nC");
        }
        printf("\nD");
    }
    else {
        printf("\nG");
        if (z > 10) {
            printf("\nH");
        }
        else {
            printf("\ni");
        }
    }
}