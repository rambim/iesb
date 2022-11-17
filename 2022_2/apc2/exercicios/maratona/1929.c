#include <stdio.h>
#include <stdlib.h>

int triangulo(int a, int b, int c);

int main()
{
    int a,b,c,d;

    scanf("%d %d %d %d",&a,&b,&c,&d);

    if (triangulo(a,b,c) || triangulo(a,b,d) ||
        triangulo(b,c,d) || triangulo(a,c,d) )
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

}

int triangulo(int a, int b, int c)
{
    if ((abs(b-c) < a && a < b + c) ||
        (abs(a-c) < b && b < a + c) ||
        (abs(a-b) < c && c < a + b) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}