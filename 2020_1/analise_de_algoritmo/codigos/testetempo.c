#include <stdio.h>
#include <stdlib.h>
#include "omp.h"


int main()

{
    double t1,t2;
    int i,j;


 /*   atribuições
  i =2;
  i = 3 * 3;
  i = 4*b*10*500/2;
inscremento
    i++;
    ++i;
    ++i++;

     i = i++;

atribuições por funções definidas em bibliotecas
a nivel de maquina

    ex: javascript  math.pow(w);

comandos de leitura e escrita ()

acessar elemento de um vetor

custo zero:
if ();
for();
while();
declaração de variável;

*/

    t1 = omp_get_wtime();

    for(i=0;i<10000;i++)
    {
        for(j=0;j<1000;j++)
        {
            i = i;
            j = j;
        }
    }

    t2 = omp_get_wtime();

    printf("tempo gasto = %lf",t2-t1);
}