/*
ANÁLISE DE ALGORTIMOS
ALUNOS:
	Maurício Barbosa - 1712130037
	Milena Nobre     - 1722130027
QUESTÃO 02:
	A) Solução do SUBSET SUM utilizando programação dinâmica que informe 
		pelo menos 1 subconjunto que atende a capacidade informada.
*/
#include <stdio.h>
#include <vector>
#include "omp.h"
#define maxN 15	// tamanho maximo do conjunto
#define CAPACIDADE 45 //valor maximo da soma

using namespace std; // para utilizar os comandos de C++

bool tabela[maxN][CAPACIDADE];
int main(){	
	
	//int conjunto[] = {5, 4, 10, 8, 9, 6, 7, 15, 11, 2, 3, 20, 41, 1, 12}; // 15 elementos
	int conjunto[] = {5, 4, 10, 8, 9, 6, 7, 15, 11, 2, 3, 20, 41, 1, 12, 16, 30, 27, 33, 18}; // 20 elementos
	//int conjunto[] = {5, 4, 10, 8, 9, 6, 7, 15, 11, 2, 3, 20, 41,
	//				1, 12, 16, 30, 27, 33, 18, 25, 44, 30, 14, 31, }; 	//25 elementos
	
	int tam = sizeof(conjunto) / sizeof(int); // pega tamanho do vetor 
	vector<int> subConjunto;
	
	int i, b, aux; //contadores
	bool s;
	
	double inicio = omp_get_wtime();
	
		printf("========================================= \nCONJUNTO: [ ");
		for(i = 0; i < tam; i++){ // mostrando o conjunto
			printf("%d ", conjunto[i]);
			tabela[i][0] = true; //inicializa a primeira coluna
		}
		tabela[0][0] = true;
		printf("]\n");   
		
		
		//inicio do subset-Sum:
		for(b = 1; b <= CAPACIDADE; b++){
			//zerando a primeira linha
			tabela[0][b] = false; 
			for(i = 1; i <= tam; i++){
				//se ja tiver conseguido esta subsoma s == 1:
				s = tabela[i-1][b];
 
				//se ainda nao tiver conseguido a subsoma e este elemento for viavel:
				if(s == false && conjunto[i] <= b){
					s = tabela[i-1][b-conjunto[i]];
				}
				tabela[i][b] = s;
			}
		}	
						
		if(tabela[tam][CAPACIDADE]){		
			i = tam;
			b = CAPACIDADE;
			aux = tabela[i][b];
		 
			while(aux){
				if(tabela[i][b] != tabela[i-1][b]){ //significa que o i faz parte do subconjunto
					if(i > 0){
						subConjunto.push_back(conjunto[i]);
					}				
					b -= conjunto[i];
				}
				i--;
				aux = tabela[i][b];
			}
				
			printf("subsonjunto [");	 
				for(i=0; i<int(subConjunto.size()); i++){
			 		printf("%d ", subConjunto[i]);
				}
				subConjunto.clear();
			printf("]\n");
		}else{
			printf("Nao existe subconjuntos que possuem a soma igual a capacidade\n");
		}	
		
		double fim = omp_get_wtime();
    	printf("Tempo utilizado : %f\n", fim-inicio);	

}

