#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct Pilha{
	
	struct Registro* topo_pilha;
	
}Pilha;

typedef struct Registro{
	
	int valor_elemento;
	struct Registro* proximo_elemento;
	
}Registro;

Pilha* criar_pilha1(void){
	
	Pilha* criar_pilha1 = (Pilha*)malloc(sizeof(Pilha));
	criar_pilha1 -> topo_pilha = NULL;
	
	return criar_pilha1;
}

Registro* criar_registro1(void){
	
	Registro* criar_registro1 = (Registro*)malloc(sizeof(Registro));
	criar_registro1 -> proximo_elemento = NULL;
	criar_registro1 -> valor_elemento = 0;
	
	return criar_registro1;
}

void push(Pilha* pilha1, int valor){
	
	Registro* colocar_elemento = criar_registro1();
	colocar_elemento->valor_elemento = valor;
	
	if(pilha1->topo_pilha == NULL){
		
		pilha1->topo_pilha = colocar_elemento;
	}
	else{
		colocar_elemento->proximo_elemento = pilha1->topo_pilha;
		pilha1->topo_pilha = colocar_elemento;
	}
	
}

int pop(Pilha* pilha1){
	
	Registro* aux;
	aux = NULL;
	int valor_retornado;
	
	if(pilha1->topo_pilha != NULL){
		
		aux = pilha1->topo_pilha;
		valor_retornado = aux->valor_elemento;
		pilha1->topo_pilha = aux->proximo_elemento;
		free(aux);
		
		return valor_retornado;
		
	}
	else{
		return 0;
	}
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	Pilha* pilha1;
	char* expressao;
	int j;

	
	expressao = (char*)malloc(sizeof(char)*500);
	

	printf("Digite a expressão que você deseja saber se está CORRETA/INCORRETA: ");
	
		pilha1 = criar_pilha1();
		scanf("%s", expressao);
		
		for(j=0;j<strlen(expressao);j++){
			if(expressao[j] == '('){
				push(pilha1, 1);
			}
			else{
				if(expressao[j] == ')'){
					if(pop(pilha1) == 0){
						printf("\nA expressão está incorreta.");
						return 0;
					}
				
				}
			}
		}
		
		if(pilha1->topo_pilha == NULL){
			printf("\nA expressão está correta.");
		}
		else{
			printf("\nA expressão está incorreta.");
		}
		
		free(pilha1);
}

