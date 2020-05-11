/*
ANÁLISE DE ALGORTIMOS
ALUNOS:
	Maurício Barbosa - 1712130037
	Milena Nobre     - 1722130027
QUESTÃO 03:
	A) Solução do subset sum utilizando o método de backtracking
		resultando em TODOS os subconjuntos que atendem a capacidade
*/

#include <stdio.h> 
#include <stdlib.h> 
#include "omp.h"

void printSubconjuntos(int A[], int size) { 
	printf("[ ");
	for(int i = 0; i < size; i++) { 
		printf("%d ", A[i]); 
	} 
	printf("]\n"); 
} 

void subset_sum(int conjunto[], int subConj[], int conjuntoTam, int subConjTam, int soma, int iterando, int const capacidade) { 
	if(capacidade == soma) { 
		// achou subconjunto manda imprimir
		printSubconjuntos(subConj, subConjTam); 
		// segue para o próximo item
		subset_sum(conjunto, subConj, conjuntoTam, subConjTam-1, soma - conjunto[iterando], iterando + 1, capacidade);  
		return; 
	} else	{ 
		for( int i = iterando; i < conjuntoTam; i++ ) { 
			subConj[subConjTam] = conjunto[i]; 
			subset_sum(conjunto, subConj, conjuntoTam, subConjTam + 1, soma + conjunto[i], i + 1, capacidade); 
		} 
	} 
}  
void gerando(int conjunto[], int tamanho, int capacidade){ 
	int *subConj = (int *)malloc(tamanho * sizeof(int)); 
	subset_sum(conjunto, subConj, tamanho, 0, 0, 0, capacidade);
	free(subConj); 
} 

int main() { 
	//int conjunto[] = {5, 4, 10, 8, 9, 6, 7, 15, 11, 2, 3, 20, 41, 1, 12}; // 15 elementos
	//int conjunto[] = {5, 4, 10, 8, 9, 6, 7, 15, 11, 2, 3, 20, 41, 1, 12, 16, 30, 27, 33, 18}; // 20 elementos
	int conjunto[] = {5, 4, 10, 8, 9, 6, 7, 15, 11, 2, 3, 20, 41,
					1, 12, 16, 30, 27, 33, 18, 25, 44, 30, 14, 31}; 	//25 elementos
	int tam = sizeof(conjunto) / sizeof(int);
	int capacidade = 50;
	
	double inicio = omp_get_wtime();
	gerando(conjunto, tam, capacidade); 
	double fim = omp_get_wtime();
    printf("Tempo utilizado : %f\n", fim-inicio);
    
	return 0; 
} 

