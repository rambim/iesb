#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    x = funcA(3);
    printf("\n %d",x);
    return 0;
}

int funcA(int a){
    int i;
    for (i = 0; i < 5; i++)
    {
        a = a + 2;
    }
    printf("\n %d",a);
    return 3;
}