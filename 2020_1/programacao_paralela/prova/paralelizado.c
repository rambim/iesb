#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include "string.h"
#include "locale.h"

// \ThiagoSantana\Desktop\Paralela\arquivo.txt


//Protótipos das funções
void funcao_paralela(char * palavra, char * txt, int tamanhoPalavra);
void funcao_sequencial(char * palavra, char * txt, int tamanhoPalavra);

int main(int arC, char *argV[]) {
    
    setlocale(LC_ALL, "Portuguese");
    
    int tamanhoArquivo;
    char caminhoarq[100];
    char *palavra;
    
	//Entrada necessária para encontrar o arquivo
    printf("Digite o caminho do arquivo desejado: ");
    scanf("%s", caminhoarq);
    
    //Guarda a palavra
    palavra = argV[1];
    
    printf("\n-Resultado da Execução \n\n");

    int tamanhoPalavra = strlen(palavra);

	//Abrindo o arquivo
    FILE *arquivo = fopen(caminhoarq, "r");

	//Voltando o ponteiro para o final do arquivo
    fseek(arquivo, 0, SEEK_END); 

	//Voltando o ponteiro para o inicio do arquivo
    fseek(arquivo, 0, SEEK_SET);
    
	// Guarda o tamanho do arquivo 
    tamanhoArquivo = ftell(arquivo); 

	//Alocando Memória
    char * txt = (char*)malloc(tamanhoArquivo);

	int i = 0;
    if(arquivo != NULL) {
		//Função que faz a leitura do arquivo e o grava na variavel do primeiro parametro
        fread(txt, tamanhoArquivo, 1, arquivo);
        funcao_sequencial(palavra, txt, tamanhoPalavra);
        funcao_paralela(palavra, txt, tamanhoPalavra);
    } else {
        printf("Erro na abertura do arquivo.\n");
    }
    free(txt);//Desalocando Memória
}

void funcao_paralela(char * palavra, char * txt, int tamanhoPalavra) {
    
    double start, end;
    int stop = 0;
    start = omp_get_wtime();
    omp_set_num_threads(1);

    #pragma omp parallel
    {
        int i = 0, j = 0, k = 0, l = 0;
        int codThread = omp_get_thread_num(); //pega o número de threds
        int ThreadsCriadas = omp_get_num_threads();  //threds criadas

        for(j = codThread * tamanhoPalavra; j < strlen(txt) && !stop; j += (tamanhoPalavra *  ThreadsCriadas)) {
			//indice que a thread está começando
	        for(k = j; k < j + tamanhoPalavra; k++){
				//Comparação letra do arquivo.txt com a letra da palavra que deseja encontrar
				if(txt[k] == palavra[i]) {
		                    i++;
		                    //checar os próximos caracteres para saber se é a palavra desejada 
		                    for(l = 1; l < tamanhoPalavra; l++) { 
		                    //Se bater interrompe a execução a outra tread
		                    	if(txt[l + k] == palavra[l]) i++; //Se i=tamanho da palavra  = palavra encontrada
		                    	else {
					   				i = 0; 
		                        	break;
		                    	}
				    		}	
		    	}
		        if(i == tamanhoPalavra) {
		            //Descobrir qual a thread que encontrou
		            //Se houver erro o for será interrompido
				  	printf("Palavra Encontrada pela thread = %d!! (Execução - Paralela)", codThread); 
		            stop = 1;
		            break;
		        } else i = 0; 
	        }
        }
    }
    printf("\nMédia Tempo Execução Paralela: %f\n", (omp_get_wtime() - start)/5 );
}


void funcao_sequencial(char * palavra, char * txt, int tamanhoPalavra) {

    double start;
    double end;
	int i = 0, j;
	
    start = omp_get_wtime();

    for(j = 0; j < strlen(txt) && i != tamanhoPalavra; j++) {
        if(txt[j] == palavra[i]) i++; //Se i=tamanho da palavra  = palavra encontrada
        else i = 0;
        if(i == tamanhoPalavra) 
			printf("Palavra Encontrada - Execução Serial\n");
    }
    printf("Média Tempo Execução Serial: %f\n\n", (omp_get_wtime() - start) / 5);
}