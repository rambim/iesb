#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	int qtd;
	struct registro *inicio;
}lista;

typedef struct registro{
	char letra;
	struct registro *prox;
}registro;

lista *alocaLista();
registro *alocaRegistro();
void pushPile(lista *l, char c);
void showPile(lista *l);

int main() {
	lista *list;
	
	char *input;
	int i,a,b, wrong = 0;
	
	input = (char*)malloc(sizeof(char)*9999);
	
	fflush(stdin);
	
	printf("\nDigite o input: ");
	gets(input);
	
	for(i=0;i<strlen(input);i++){
		if(input[i] == 'A' || input[i] == 'B'){
				list = alocaLista();
	for( a=0;a<strlen(input);a++){
		pushPile(list,input[a]);
	}
		} else {
			printf("\nLetras invalidas digitadas no input!\n");
		}
	} 
	
	

	showPile(list);
	
	
	
	
	return 0; 
}


lista *alocaLista(){
	lista *nova;
	nova = (lista*)malloc(sizeof(lista));
	nova->qtd = 0;
	nova->inicio = NULL;
	
	return nova;
};

registro *alocaRegistro(){
	registro *novo;
	novo = (registro*)malloc(sizeof(registro));
	novo->prox = NULL;
};

void pushPile(lista *l, char c){
	registro *newReg;
	registro *aux;
	newReg = alocaRegistro();
	newReg->letra = c;
	
	
	if(l->qtd == 0){
		l->inicio = newReg;
	} else {
		newReg->prox = l->inicio;
		l->inicio = newReg;
	}
	l->qtd++;
}

void showPile(lista *l){
	registro *aux;
	
	if(l->qtd == 0){
		printf("\nNao existem elementos na pilha.\n");
	} else {
		aux = l->inicio;
		printf("\nSaida = ");
		while(aux != NULL){
			printf("%c",aux->letra);
			aux = aux->prox;
		}
	}
}

