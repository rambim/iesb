#include<stdio.h>
#include<stdlib.h>

//QUESTAO 5

typedef struct lista{
	int quantidade;
	struct registro *inicio;
	struct registro *fim;
}lista;

typedef struct registro{
	int valor;
	struct registro *proximo;
}registro;

lista *alocar_lista();
registro *alocar_registro();
void mostrar(lista *l1);
void push(lista *l1, int valor);
void pop(lista *l1);
void menu();
bool empty(lista *l1);

int main(){
	
	menu();

	return 0;
}

void menu(){
	
	lista *l1;
	
	l1 = alocar_lista();
	int opcao=0;
	
	while(opcao!=4){
		printf("\n");
		mostrar(l1);
		printf("\n");
		printf("1 - push\n");
		printf("2 - pop\n");
		printf("3 - empty\n");
		printf("4 - sair\n");
		
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:{
				system("cls");
				printf("\n");
				printf("digite os valores para colocar na fila e digite 99 para voltar ao menu:\n");
				int valor;
				scanf("%d",&valor);
				while(valor!=99){
					push(l1,valor);
					scanf("%d",&valor);
				}
				break;
			}
			case 2:{
				system("cls");
				system("\n");
				pop(l1);
				break;
			}
			case 3:{
				system("cls");
				system("\n");
				if(empty(l1)==true){
					printf("\n");
					printf("a fila esta vazia\n");
					printf("\n");
				}else{
					printf("\n");
					printf("a fila nao esta vazia\n");
					printf("\n");
				}
				break;
			case 4:{
				break;
			}
			default:{
				system("cls");
				printf("opcao invalida, tente outra\n");
				break;
			}
			}
		}
	}
}

lista *alocar_lista(){
	lista *l1;
	l1 = (lista *)malloc(sizeof(lista));
	l1->quantidade=0;
	l1->inicio=NULL;
	l1->fim=NULL;
	return l1;
}

registro *alocar_registro(){
	registro *reg;
	reg = (registro *)malloc(sizeof(registro));
	reg->valor=0;
	reg->proximo=NULL;
	return reg;
}

bool empty(lista *l1){
	if(l1->quantidade==0){
		return true;
	}else{
		return false;
	}
}

void mostrar(lista *l1){
	registro *reg;
	reg=alocar_registro();
	if(l1->quantidade==0){
		printf("a fila esta vazia.\n");
	}else{
		printf("\n");
		printf("quantidade de elementos na fila: %d\n",l1->quantidade);
		printf("\n");
		printf("elementos na fila:\n");
		printf("\n");
		reg = l1->inicio;
		printf("%d",reg->valor);
		printf("\n");
		while(reg->proximo!=NULL){
			reg = reg->proximo;
			printf("%d",reg->valor);
			printf("\n");
		}
	}
}

void push(lista *l1, int valor){
	registro *reg, *aux;
	reg = alocar_registro();
	aux = alocar_registro();
	
	reg->valor=valor;
	
	if(l1->quantidade==0){
		l1->inicio=reg;
		l1->quantidade++;
	}else{
		if(l1->fim==NULL){
			l1->fim=reg;
			l1->inicio->proximo=l1->fim;
			l1->quantidade++;
		}else{
			aux = l1->fim;
			while(aux->proximo!=NULL){
				aux=aux->proximo;
			}
			aux->proximo=reg;
			l1->quantidade++;
		}	
	}
}

void pop(lista *l1){
	registro *reg;
	reg = alocar_registro();
	
	if(l1->quantidade==0){
		printf("\n");
		printf("a fila esta vazia\n");
		printf("\n");
	}else{
		if(l1->quantidade==1){
			int valor;
			valor = l1->inicio->valor;
			l1->inicio=NULL;
			l1->fim=NULL;
			l1->quantidade--;
			printf("\n");
			printf(" valor %d retirado.\n",valor);
			printf("\n");
		}else{
			int valor;
			valor = l1->inicio->valor;
			l1->inicio = l1->fim;
			l1->fim = l1->inicio->proximo;
			l1->quantidade--;
			printf("\n");
			printf(" valor %d retirado.\n",valor);
			printf("\n");
		}	
	}
}














