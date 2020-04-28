#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	int qtd;
	struct registro *inicio;
}lista;

typedef struct registro{
	int valor;
	struct registro *prox;
}registro;

lista *alocaLista();
registro *alocaRegistro();
void pushPile(lista *l, int x);
int popPile(lista *l);
void showPile(lista *l);

int main() {
	lista *list;
	int qtd,i;
	char *input;
	int closed = 0, open = 0;
	
	list = alocaLista();
	input = (char*)malloc(sizeof(char)*9999);
	
	fflush(stdin);
	
	printf("\nDigite a expressao: \n");
	gets(input);
	
	for(i=0;i<strlen(input);i++){
		if(input[i] == '('){
			pushPile(list, 1);
			open++;
		}
		if(input[i] == ')'){
			if(popPile(list) == 1){
			closed++;
			} else {
				closed--;
			}
		}
	}
	
	
	if(open == closed){
		printf("\nQuantidade de parenteses fechando esta correta!\n");
	} else {
		printf("\nQuantidade de parenteses fechando esta incorreta!\n");
	}
	
	
	return 0;
}

lista *alocaLista(){
	lista *nova;
	nova = (lista*)malloc(sizeof(lista));
	nova->qtd = 0;
	nova->inicio = NULL;
	
	return nova;
}

registro *alocaRegistro(){
	registro *novo;
	novo = (registro*)malloc(sizeof(registro));
	novo->valor = 0;
	novo->prox = NULL;
	
	return novo;
}

void pushPile(lista *l, int x){
	registro *newReg;
	registro *aux;
	newReg = alocaRegistro();
	newReg->valor = x;
	
	
	if(l->qtd == 0){
		l->inicio = newReg;
	} else {
		newReg->prox = l->inicio;
		l->inicio = newReg;
	}
	l->qtd++;
}

int popPile(lista *l){
	registro *aux;
	int result;
	aux = NULL;
	
	if(l->qtd == 0){
		return -1;
	} else {
		aux = l->inicio;
		result = aux->valor;
		l->inicio = aux->prox;
		free(aux);
		l->qtd--;
		return result;
	}
}

void showPile(lista *l){
	registro *aux;
	
	if(l->qtd == 0){
		printf("\nNao existem elementos na pilha.\n");
	} else {
		aux = l->inicio;
		while(aux != NULL){
			printf("\nValor - %d",aux->valor);
			aux = aux->prox;
		}
	}
}


