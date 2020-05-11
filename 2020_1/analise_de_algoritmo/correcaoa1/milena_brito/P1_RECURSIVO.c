/*
ANÁLISE DE ALGORTIMOS
ALUNOS:
	Maurício Barbosa - 1712130037
	Milena Nobre     - 1722130027
QUESTÃO 01:
	A) Solução recursiva do SUBSET SUM que informa se existe algum 
		subconjunto que é igual a capacidade informada
	    TRUE OU FALSE!   
*/

#include<stdio.h> 
#include "omp.h"
#define CAPACIDADE 35 // QUANTIDADE PARA SOMATÓRIA

int boolOcorrenciam(int vetor[], int tam, int capacidade){ 

    if (capacidade == 0) {
    	return 1; // como capacidade é ZERO qualquer soma será validada como true
	}
    if (tam == 0 && capacidade != 0) {
    	return 0; // ele chegou no final do vetor[] e n possui nenhuma somatória == capacidade
	}

    if (vetor[tam - 1] > capacidade) {
        return boolOcorrenciam(vetor, tam - 1, capacidade); 
    }       
    return boolOcorrenciam(vetor, tam - 1, capacidade) || 
           boolOcorrenciam(vetor, tam - 1, capacidade - vetor[tam - 1]);  
}   


int main(){
	int vetor[] = {5, 4, 10, 8, 9, 6, 7, 15, 11, 2, 3, 20, 41, 1, 12}; 	
	int tam = sizeof(vetor) / sizeof(int); // pega tamanho do vetor 
	int i; 
	
	printf("========================================= \nVETOR: [");
	for(i = 0; i < tam; i++){ // mostrando o conjunto
		printf("%d ", vetor[i]);
	}
	printf("]\n");   
       
    printf("EXISTENCIA DE SUBCONJUNTOS QUE RESULTAM = %d\n", CAPACIDADE);
    
    double inicio = omp_get_wtime();
    if(boolOcorrenciam(vetor, tam, CAPACIDADE)){  // MOSTRA SE EXISTE SUBCONJUNTOS (TRUE)	
		printf("TRUE\n"); 
	}else{	
		printf("FALSE\n");
	}
	
	double fim = omp_get_wtime();
    printf("Tempo utilizado : %f\n", fim-inicio);
    
	printf("========================================");
	return 0;
}
