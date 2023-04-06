#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,y;
    scanf("%lf %lf",&x,&y);

    // printf("\n X = %lf Y = %lf",x,y);

    if (x>0 && y> 0)
    {
        printf("Q1");
    }
    else
    {
        if (x<0 && y <0)
        {
            printf("Q3");
        }
        else
        {
            if (x > 0 && y < 0)
            {
                printf("Q4");
            }
            else
            {
                if (x<0 && y > 0)
                {
                    printf("Q2");
                }
                else
                {
                    if (x==0 && y ==0)
                    {
                        printf("Origem");
                    }
                    else
                    {
                        if (x==0){
                            printf("Eixo Y");
                        }
                        else
                        {
                            printf("Eixo X");
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    return 0;
}