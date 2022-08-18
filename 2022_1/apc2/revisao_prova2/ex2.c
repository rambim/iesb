#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i,j;
    int a = 0;
    for(i=0;i<5;i++)    
    {
        for(j=i;j<5;j++)        
        {
            a = a + 1;
        }
    }
    printf("\n %d",i);
    return 0;
    
}