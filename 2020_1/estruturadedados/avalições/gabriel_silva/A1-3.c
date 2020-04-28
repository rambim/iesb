#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int qtd;
	struct registro *inicio;
	struct registro *fim;
}lista;

typedef struct registro{
	int valor;
	struct registro *prev;
	struct registro *prox;
}registro;

lista *alocaLista();
registro *alocaRegistro();
void pushStart(lista *l, int x);
void pushEnd(lista *l, int x);
void showList(lista *l);
void showFromEnd(lista *l);
void popStart(lista *l);
void popEnd(lista *l);
int isPrim(int x);
void removePrims(lista *l);

void menu(lista *list);


int main() {
	lista *list;
	
	list = alocaLista();
	
	menu(list);
	
	return 0;
}

lista *alocaLista() {
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
	novo->prev = NULL;
	novo->prox = NULL;
	
	return novo;
}

void pushStart (lista *l, int x) {
	registro *newReg;
	
	newReg = alocaRegistro();
	newReg->valor = x;
	
	
	if(l->qtd == 0){
		l->inicio = newReg;
		l->fim = newReg;
	} else {
		l->inicio->prev = newReg;
		newReg->prox = l->inicio;
		l->inicio = newReg;	
	}
	l->qtd++;
}

void pushEnd(lista *l, int x) {
	registro *newReg;
	
	newReg = alocaRegistro();
	newReg->valor = x;
	
	if(l->qtd == 0) {
		l->inicio = newReg;
		l->fim = newReg;
	} else {
		l->fim->prox = newReg;
		newReg->prev = l->fim;
		l->fim = newReg;
	}
	l->qtd++;
}

void showList(lista *l) {
	registro *aux, *end;
	aux = l->inicio;
	end = l->fim->prox;
	
		while(aux != end){
			printf("\nValor - %d\n",aux->valor);
			aux = aux->prox;
		}
	}

void showFromEnd(lista *l) {
	registro *aux, *start;
	aux = l->fim;
	start = l->inicio->prev;
	
		while(aux != start) {
			printf("\nValor - %d\n",aux->valor);
			aux = aux->prev;
		}
	}

void popStart(lista *l) {
	registro *aux, *prev;
	
	if(l->qtd == 0){
		printf("\n Lista Vazia!\n");
	}else {
		aux = l->inicio->prox;
		prev = l->inicio;
		l->inicio = aux;
		printf("\n%d removido com sucesso.\n",prev->valor);
		free(prev);
		l->qtd--;
	}
	
}

void popEnd(lista *l){
	registro *aux, *prev;
	
	if(l->qtd == 0){
		printf("\n Lista vazia!\n");
	} else {
		aux = l->fim->prev;
		prev = l->fim;
		l->fim = aux;
		printf("\n%d removido com sucesso.\n",prev->valor);
		free(prev);
		l->qtd--;
	}
}

int isPrim(int x) {
	int div = 2;
	
	if (x == 1) {
		return 0;
	} else {
	 for (div; div<x; div++){
			if(x%div == 0){
				return 0;
			} 
		}
		return 1;
	}
}

void removePrims(lista *l) {
	registro *aux, *prev, *end;
	end = l->fim->prox;
	
	if(l->qtd == 0){
		printf("\nNao existem numeros para serem removidos.\n");
	} else {
		aux = l->inicio;
		prev = NULL;
		
		while(aux != end){
			if(isPrim(aux->valor)){
				if(aux == l->inicio){
					prev = l->inicio;
					aux = l->inicio->prox;
					l->inicio = aux;
					free(prev);
				} else if(aux == l->fim){
					prev = l->fim;
					aux = l->fim->prev;
					l->fim = aux;
					free(prev);
				} else {
					prev = aux->prev;
					prev->prox = aux->prox;
					free(aux);
					aux = prev->prox;
					aux->prev = prev;
				}
			}
			aux = aux->prox;
		}
		
	}
	l->qtd--;
}

void menu(lista *list){
	int opt, num;
	
	do{
		printf("\n---------- MENU ----------\n1 - Inserir no inicio\n2 - Inserir no fim\n3 - Remover do inicio\n4 - Remover do fim\n5 - Mostrar lista do inicio\n6 - Mostrar Lista do fim\n7 - Remover Primos\n8 - Sair\n->");
		scanf("%d",&opt);
		
		switch(opt){
		case 1: printf("\nDigite o numero que deseja inserir: \n");
		scanf("%d",&num);
		pushStart(list, num);
		break;
		
		case 2: printf("\nDigite o numero que deseja inserir: \n");
		scanf("%d",&num);
		pushEnd(list, num);
		break;
		
		case 3: popStart(list);
		break;
		
		case 4: popEnd(list);
		break;
		
		case 5: if(list->qtd == 0){
			printf("\nLista vazia!\n");
		} else {
			showList(list);
		}
		break;
		
		case 6: if(list->qtd == 0){
			printf("\nLista vazia!\n");
		} else {
			showFromEnd(list);
		}
		break;
		
		case 7: removePrims(list);
		removePrims(list);
		printf("\n Todos os nums. primos foram removidos da lista.\n");
		break;
		
		case 8: printf("\nSaindo do programa....");
		break;
		
		default: printf("\nOpcao invalida!\n");
		break;		
	}
	
	} while(opt != 8);
}
