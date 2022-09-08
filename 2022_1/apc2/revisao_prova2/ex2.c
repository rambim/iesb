#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int a = 0;
    for(i=0;i<10;i++)    
    {
        for(j=i;j<10;j++)        
        {
            a = a + 1;
        }
    }
    printf("\n %d",a);
    return 0;
}