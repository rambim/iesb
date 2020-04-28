#include<stdio.h>
#include<stdlib.h>

//QUESTÃO 4

typedef struct lista{
	int quantidade;
	struct registro *inicio;
}lista;

typedef struct registro{
	int valor;
	struct registro *proximo;
}registro;

lista *alocar_lista();
registro *alocar_registro();
void adicionaValor(lista *l1, int valor);
void menu();
void mostrarLista(lista *l1);
void removeValor(lista *l1, int valor);
void procuraValor(lista *l1, int valor);


int main(){

	menu();
	
	return 0;
}

void menu(){
	
	lista *l1, *l2;
	l1 = alocar_lista();
	l2 = alocar_lista();
	
	int opcao =0;
	
	int valor=0;

	
	while(opcao!=4){
		printf("\n");
		printf("escolha uma opcao abaixo:\n");
		printf("\n");
	
		printf("1 - adicionar valores na lista\n");
		printf("2 - remover valores da lista\n");
		printf("3 - buscar um numero dentro da lista e mostrar o valor do registro imediatamente anterior e do imediatamente posterior\n");
		printf("4 - sair\n");
	
		printf("\n");
		mostrarLista(l1);
		printf("\n");
		
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:{
				system("cls");
				printf("digite os valores para dicionar e digite 99 para voltar ao menu.\n");
				scanf("%d",&valor);				
				while(valor!=99){						
					adicionaValor(l1,valor);
					scanf("%d",&valor);
				}
				system("cls");
				break;
			}
			case 2:{
				system("cls");
				printf("digite o valor para remover da lista:\n");
				scanf("%d",&valor);
				removeValor(l1,valor);
				break;
			}
			case 3:{
				system("cls");
				printf("digite o valor para procurar:\n");
				scanf("%d",&valor);
				procuraValor(l1,valor);
				break;
			}
			case 4:{
				break;
			}
			default:
				system("cls");
				printf("opcao invalida, tente outra.\n");			
		}
	}
	
}

void procuraValor(lista *l1, int valor){
	registro *reg, *aux;
	
	int mostrarSeEncontrou=0;
	
	aux = alocar_registro();
	reg = alocar_registro();
	
	if(l1->quantidade==0){
		printf("\n");
		printf("a list esta vazia\n");
		printf("\n");
	}else{
		reg = l1->inicio;
		if(reg->valor==valor){
			mostrarSeEncontrou=1;
			printf("\n");
			printf("valor do registro imediatamente anterior: NULL\n");
			printf("valor do registro imediatamente posterior: %d\n",reg->proximo->valor);
			printf("\n");
		}else{
			while(reg->proximo!=NULL){
				aux = reg;
				reg = reg->proximo;
				if(reg->valor==valor){
					mostrarSeEncontrou=1;
					printf("\n");
					printf("valor do registro imediatamente anterior: %d\n",aux->valor);
					if(reg->proximo==NULL){
						printf("valor do registro imediatamente posterior: NULL\n");
						printf("\n");
					}else{
						printf("valor do registro imediatamente posterior: %d\n",reg->proximo->valor);
						printf("\n");
						break;
					}
				}
			}
		}	
	}
	
	if(mostrarSeEncontrou==0){
		printf("\n");
		printf("o valor %d nao esta na lista\n",valor);
		printf("\n");
	}
}

void removeValor(lista *l1, int valor){
	registro *reg, *aux;
	reg = alocar_registro();
	aux = alocar_registro();
	
	int valorQuantidade = l1->quantidade;
	
	reg = l1->inicio;
	
	if(reg->valor==valor){
		l1->inicio = reg->proximo;
		l1->quantidade--;
	}else{
		aux = reg;
		reg = reg->proximo;
		while(reg->proximo!=NULL){
			if(reg->valor==valor){
				aux->proximo = reg->proximo;
				l1->quantidade--;
				break;
			}
			aux = reg;
			reg = reg->proximo;
		}
		if(reg->valor==valor){
			aux->proximo = reg->proximo;
			l1->quantidade--;
		}
	}
	
	if(valorQuantidade==l1->quantidade){
		printf("\n");
		printf("valor nao encontrado\n");
		printf("\n");
	}else{
		printf("\n");
		printf("valor %d removido\n",valor);
		printf("\n");
	}
}

void mostrarLista(lista *l1){
	registro *reg, *aux;
	reg = alocar_registro();
	aux = alocar_registro();
	
	if(l1->quantidade==0){
		printf("a lista esta vazia.\n");
	}else{
		printf("\n");
		printf("mostrando a lista:\n");
		printf("\n");
		reg = l1->inicio;
		printf("%d/",reg->valor);
		reg = reg->proximo;
		while(reg->proximo!=NULL){
			printf("%d/",reg->valor);
			reg = reg->proximo;
		}
		printf("%d/",reg->valor);
	}
	printf("\n");
}

lista *alocar_lista(){
	lista *l1;
	l1 = (lista *)malloc(sizeof(lista));
	l1->quantidade = 0;
	l1->inicio = NULL;
	return l1;
}

registro *alocar_registro(){
	registro *reg;
	reg = (registro *)malloc(sizeof(registro));
	reg->valor = 0;
	reg->proximo = NULL;
	return reg;
}

void adicionaValor(lista *l1, int valor){
	registro *reg, *aux;
	
	reg = alocar_registro();
	aux = alocar_registro();
	
	reg->valor = valor;
	
	if(l1->quantidade==0){
		l1->inicio = reg;
		l1->quantidade++;
	}else{
		aux = l1->inicio;
		while(aux->proximo!=NULL){
			aux = aux->proximo;
		}
		aux->proximo = reg;
		l1->quantidade++;
	}
}



















