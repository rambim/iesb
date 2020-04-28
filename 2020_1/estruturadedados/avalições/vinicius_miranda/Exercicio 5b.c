#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct Pilha{
	
	struct Registro* topo_pilha;
	
}Pilha;

typedef struct Registro{
	
	char conteudo_elemento;
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
	criar_registro1 -> conteudo_elemento = 0;
	
	return criar_registro1;
}

void push(Pilha* pilha1, char valor){
	
	Registro* colocar_elemento = criar_registro1();
	colocar_elemento->conteudo_elemento = valor;
	
	if(pilha1->topo_pilha == NULL){
		
		pilha1->topo_pilha = colocar_elemento;
	}
	else{
		colocar_elemento->proximo_elemento = pilha1->topo_pilha;
		pilha1->topo_pilha = colocar_elemento;
	}
	
}

char pop(Pilha* pilha1){
	
	Registro* aux;
	aux = NULL;
	char valor_retornado;
	
	if(pilha1->topo_pilha != NULL){
		
		aux = pilha1->topo_pilha;
		valor_retornado = aux->conteudo_elemento;
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
	int i, flag=0;
	

	
	expressao = (char*)malloc(sizeof(char)*500);
	

	printf("Digite a(as) expressão(ões) para comparação: ");
	
		pilha1 = criar_pilha1();
		scanf("%s", expressao);
		
		for(i=0;i<strlen(expressao);i++){
		if(expressao[i] != 'D'){
			if(expressao[i] != 'C'){
				if(flag!=1){
					if(expressao[i] == 'A'){
					push(pilha1, 'A');
					}
						if(expressao[i] == 'B'){
							push(pilha1, 'B');
						}
				}
				else{
					if(pop(pilha1) != expressao[i]){
						printf("\nA comparação dos elementos não é equivalente.");
						return 0;
					}
					else{
						continue;
					}
				}
			}
			else{
				flag++;
			}
		}else{
			flag--;
		}
	}
	
	if(pilha1->topo_pilha != NULL){
		printf("\nA comparação dos elementos não é equivalente.");
	}
	else{
		printf("\nA comparação de todos os elementos está certa.");
	}
		free(pilha1);
}

