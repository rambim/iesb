#include <stdio.h>
#include <stdlib.h>

int main()
{
    double raio;
    double pi= 3.14159;

    scanf("%lf",&raio);

    printf("VOLUME = %.3lf",4/3.0 * pi * raio * raio * raio);
    printf("\n");
    return 0;
}