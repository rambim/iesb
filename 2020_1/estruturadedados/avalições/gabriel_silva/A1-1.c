#include <stdio.h>
#include <stdlib.h>

// Professror, você não pediu na questão que a fila tenha um tamanho máximo,
// MAS, como na explicação que você deu, na teoria uma fila circular tem um tamanho máximo, eu adicionei esse tamanho máximo de valor = 8
//comentado na função menu();
//Como eu não sabia se era pra adicionar, eu deixei comentado mesmo. Caso seja, ela está na função, basta descomentar o código! 
 // ***E cometar o pushList que está depois! ***

typedef struct lista {
	int qtd;
	struct registro *fim;
	struct registro *inicio;
}lista;

typedef struct registro {
	int valor;
	struct registro *prox;
}registro;


lista *alocaLista();
registro *alocaRegistro();
void pushList(lista *l, int x);
void showList(lista *l);
void popList(lista *l);
void menu();


int main() {
	lista *list;
	
	list = alocaLista();
	

	menu(list);

	return 0;
}


lista *alocaLista() {
	lista *nova;
	nova = (lista*)malloc(sizeof(lista));
	nova->inicio = NULL;
	nova->fim = NULL;
	nova->qtd = 0;
	return nova;
}

registro *alocaRegistro() {
	registro *novo;
	novo = (registro*)malloc(sizeof(registro));
	novo->valor = 0;
	novo->prox = NULL;
	return novo;
}

void pushList (lista *l, int x){
	registro *newReg, *aux;
	newReg = alocaRegistro();
	newReg->valor = x;
	
	if(l->qtd == 0) {
		l->inicio = newReg;
		l->fim = newReg;
	} else {
		aux = l->inicio;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = newReg;
		l->fim = aux->prox;
	}
	l->qtd++;
	
}

void showList(lista *l) {
	
	registro *aux;
	
	if(l->inicio == NULL) {
		printf("\nFila vazia!\n");
	} else {
		aux = l->inicio;
		while(aux != l->fim->prox){
			printf("\nValor = %d\n", aux->valor);
			aux = aux->prox;
		}
	}
}

void popList(lista *l) {
	registro *aux, *prev;
	
	if(l->qtd == 0){
		printf("\n ***Nao existem elementos na fila para remover.***\n");
	} else {
		aux = l->inicio->prox;
		prev = l->inicio;
		l->inicio = aux;
		printf("\n%d removido com sucesso.\n",prev->valor);
		free(prev);
		l->qtd--;
	}

}


void menu(lista *list){
	int opt,num;

	do {
	printf("\n---------- MENU ----------\n1 - Incluir na fila\n2 - Remover da fila\n3 - Mostrar fila\n4 - Sair\n");
	scanf("%d",&opt);
		switch(opt) {
			case 1: 
			printf("\nDigite o numero que deseja incluir: \n");
			scanf("%d",&num);
			/*if(list->qtd <= 8){
			pushList(list, num);
			} else {
				printf("\n\n***ATENCAO***\nLista cheia, nao e possivel incluir novos elementos!\n\n");
			}*/
			pushList(list,num);
			break;
			
			case 2: 
			popList(list);
			break;
			
			case 3: 
			showList(list);
			break;
			
			case 4: 
			printf("Saindo do programa...");
			break;
			
			
			default:
				printf("\nOpcao invalida!\n");
				break;
		}
 } while(opt != 4);
	
}
