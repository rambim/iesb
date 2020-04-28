#include <stdio.h>
#include <stdlib.h>

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
void showPile(lista *l);

int main(){
	int vetor[9];
	int i;
	int start, end;
	
	lista *list1, *list2;
	list1 = alocaLista();
	list2 = alocaLista();
	
	for(i=0;i<=10;i++){
		while(vetor[i] <=4){
			pushPile(list1,1);
			pushPile(list1,2);
			pushPile(list1,3);
			pushPile(list1,4);
			pushPile(list1,5);
		} while(vetor[i] >= 5){
			pushPile(list2,6);
			pushPile(list2,7);
			pushPile(list2,8);
			pushPile(list2,9);
			pushPile(list2,10);
		}
	}
	
	for(i=0;i<=10;i++){
		showPile(list1);
		showPile(list2);
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

registro *alocaRegistro() {
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

