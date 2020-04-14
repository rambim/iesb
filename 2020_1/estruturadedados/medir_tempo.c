/*


 faça um programa que calcule o tempo gasto de um programa


 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t
 
#define TAM 10000 //constante para tamanho do vetor
 

 
int main(){
 clock_t t1,t2; //variável para armazenar tempo
 int vetor[TAM]; //vetor com 10000 posições
 int p, r, a;
 p = 0;
 r = TAM; 
 int i,j=0;
 int x;
 
    
 t1 = clock(); //armazena tempo

 for(i=0;i<10000;i++)
 {
     for(j=0;j<10000;j++)
     {
        x = x;
     }
 }
 // processamento
 t2 = clock(); //tempo final - tempo inicial
 //imprime o tempo na tela
 
 printf("Tempo de execucao: %lf", (((double)t2 - (double)t1)/((CLOCKS_PER_SEC/1000))));
}