#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>



int main()
{

    float total[10] = {0};
    float valor;
    int numero;
    char tipo;
    int i;

    do
    {
        scanf("%d",&numero);

        if (numero!=-1)
        {
            scanf("%f\n",&valor);
            
            scanf("%c",&tipo);

            if (tipo == 'R')
            {
                total[numero] = total[numero] + valor;
            }
            else
            {
                total[numero] = total[numero] - valor;
            }

            
        }
    } while (numero!=-1);
    
    

    for(i=0;i<10;i++)
    {
        printf("\n Projeto %d = %f",i,total[i]);
    }
    printf("\n");
}