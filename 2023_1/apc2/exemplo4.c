#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, *ptr;

    x  = 2;
    ptr = &x;

    printf("\n x    = ", x   );
    printf("\n ptr  = ", ptr );
    printf("\n &x   = ", &x  );
    printf("\n &ptr = ", &ptr);
    printf("\n *ptr = ", *ptr);

    *ptr = 3;
    
    return 0;
}