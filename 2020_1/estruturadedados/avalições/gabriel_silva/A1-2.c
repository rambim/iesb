#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
	int qtd;
	struct registro *inicio;
	struct registro *fim;
}lista;

typedef struct registro{
	int valor, i;
	struct registro *prox;
}registro;

lista *alocaLista();
registro *alocaRegistro();
void pushPile(lista *l, int x);
int popPile(lista *l);
void showPile(lista *l);

int main() {
	lista *list;
	int cont = 0, cards, i;
	list = alocaLista();
	
	do {
		printf("Digite as cartas a serem discartadas (*SEPARADAS POR 'ESPACO'*)\n");
		scanf("%d", &cards);
		
		if(cards){
			cont = cards;
			for(i=0;i<cards;i++){
				pushPile(list, cards);
			}
			
			printf("\nCartas descartadas: \n");
			while(cards != 1){
				printf(" %d", popPile(list));
				pushPile(list,popPile(list));
			}
			if(cards != 2){
				printf(",");
				cards--;
			}
			
			if(list->qtd == 0){
				printf("\nCartas restantes: %d", popPile(list));
			}
			
		}
	} while(cards != 0);
	
	return 0;
}

lista *alocaLista(){
	lista *nova;
	nova = (lista*)malloc(sizeof(lista));
	nova->qtd = 0;
	nova->inicio = NULL;
	nova->fim = NULL;
	
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
	newReg = alocaRegistro();
	newReg->valor = x;
	
	if(l->qtd == 0){
		l->inicio = newReg;
		l->fim = newReg;
	} else {
		l->fim->prox = newReg;
		l->fim = newReg;
	}
	l->qtd++;
}

int popPile(lista *l){
	int card;
	registro *aux;
	
	aux = l->inicio;
	card = aux->valor;
	
	
	if(l->qtd == 0){
		printf("\nNao existem cartas para descartar!\n");
	} else {
		l->inicio = aux->prox;
		if(l->inicio == NULL){
			l->fim = NULL;
		}
		
		free(aux);
	}
	l->qtd--;
	
	return card;
}

void showPile(lista *l){
	
}
