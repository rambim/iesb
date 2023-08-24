#include <stdio.h> 
#include <stdlib.h>
int main()
{
    int x=5;
    int z=2;
    while(x--)
    {
        printf("\n Valores: %d + %d",x,z);
        z = z + x;
    }
    printf("\n final x = %d z = %d",x,z);
    printf("\n%d",x + z);

    return 0;
}