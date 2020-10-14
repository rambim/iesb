#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int matricula[10];
    float n1[10];
    float n2[10];
    float media[10];
    float altura[10];
    int idade[10];
    int i;

    

     for(i=0;i<10;i++)
     {
         preenche_aluno(&matricula[i], &n1[i], &n2[i], &media[i], &altura[i], &idade[i]);
     }



}

void preenche_aluno(long int * matricula, float * n1, float * n2, float * media, float * altura, int * idade)
{

}