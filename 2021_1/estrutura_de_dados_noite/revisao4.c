#include <stdio.h>
#include <stdlib.h>

typedef struct registro
{
    int numero1;
    float numero2;
} registro;

int main()
{
    registro *a;
    registro b;

    // a = malloc(???);
    a = (registro *)malloc(sizeof(registro));

    (*a).numero1 = 2;
    a->numero1 = 2;
    (*a).numero2 = 1;
    a->numero2 = 1;

    b.numero1 = 1;
    b.numero2 = 2;

    printf("\n");
    return 0;
}