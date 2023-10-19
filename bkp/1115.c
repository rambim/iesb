#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x =1 , y =1;

    int q=0;
    
    while(x!=0 && y !=0)
    {
        scanf("%d",&x);
        scanf("%d",&y);

        if (x!=0 && y!=0)
        {
            if (x > 0 && y > 0)
            {
                printf("primeiro\n");
            }
            else
            {
                if (x>0 && y<0)
                {
                    printf("quarto\n");
                }
                else
                {
                    if (x<0 && y> 0)
                    {
                        printf("segundo\n");
                    }
                    else
                    {
                        printf("terceiro\n");
                    }
                }
            }
        }

        
    }

    return 0;
}