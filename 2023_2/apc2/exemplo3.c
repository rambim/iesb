#include <stdio.h> #include <stdlib.h>
int main()
{
    int x = 0, y = 10,i;
    for(i=2;i<y;i++)
    {
        if (i%2==0)
        {
            x = x + 1;
        }
        y--;
    }
    printf("\n %d %d",x,y);
}