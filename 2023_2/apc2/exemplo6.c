#include <stdio.h> #include <stdlib.h>
int main()
{
    int x=2, y = 10,z;
    while(x!=y)
    {
        x ++;
        y --;
        z = x + y;
    }
    printf("\n %d %d %d",y, x, z + x);
}