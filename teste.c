#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main(){

    int n = 0;
    int * vet;
    int iteracao = 0;

    do{
    printf("Digite a quantidade de threads: ");
    scanf("%d", &n);
    }while(n<=0);

    vet = (int *)malloc(sizeof(int) * n);

    omp_set_num_threads(n);

#pragma omp parallel for

    for(int i = 0; i < omp_get_num_threads(); i++){
        printf("\nEu sou a Thread [ %d ]", omp_get_thread_num());
        vet[iteracao] = omp_get_thread_num();
        if(vet[0] == omp_get_thread_num()){
            printf(" Iniciando o mundo paralelo");
        }
        iteracao++;
    }

#pragma omp master
        printf("\nFIM\n");

}