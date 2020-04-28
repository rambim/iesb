#include<stdio.h>
#include<stdlib.h>

//QUESTAO 7 

typedef struct lista{
	int quantidade;
	struct registro *inicio;
	struct registro *fim;
}lista;

typedef struct registro{
	int valor;
	struct registro *proximo;
	struct registro *antes;
}registro;

lista *alocar_lista();
registro *alocae_registro();
void adicionarInicio(lista *l1, int valor);
void adicionarFim(lista *l1, int valor);
void mostrarIndo(lista *l1);
void mostrarVindo(lista *l1);
void menu();
void remover(lista *l1, int valor);
bool verificaPrimo(int valor);
void removePrimos(lista *l1);

int main(){
	
	menu();
	
	return 0;
};

void menu(){
	
	lista *l1;
	l1 = alocar_lista();
	
	lista *l2;
	l2 = alocar_lista();
	
	int opcao =1;
	
	int valor;
	
	while(opcao!=7){
	
	printf("\n");
	printf("1 - adicionar valor no inicio da lista\n");
	printf("2 - adicionar valor no fim da lista\n");
	printf("3 - mostrar valores indo da lista\n");
	printf("4 - mostrar valores vindo da lista\n");
	printf("5 - remover valores da lista\n");
	printf("6 - remover valores primos da lista\n");
	printf("7 - sair\n");
	
	scanf("%d",&opcao);
	
		switch(opcao){
			case 1:{
				system("cls");
				printf("digite os valores para adicionar no inicio da lista e digite 99 para voltar ao menu.\n");
				scanf("%d",&valor);
				while(valor!=99){
					adicionarInicio(l1,valor);
					scanf("%d",&valor);
				}
				break;
			}
			case 2:{
				system("cls");
				printf("digite os valores para adicionar no fim da lista e digite 99 para voltar ao menu.\n");
				scanf("%d",&valor);
				while(valor!=99){
					adicionarFim(l1,valor);
					scanf("%d",&valor);
				}
				break;
			}
			case 3:{
				system("cls");
				printf("mostrar valores da lista indo:\n");
				mostrarIndo(l1);
				printf("\n");
				break;
			}
			case 4:{
				system("cls");
				printf("mostrar valores da lista vindo:\n");
				mostrarVindo(l1);
				printf("\n");
				break;
			}
			case 5:{
				system("cls");
				printf("digite o valor para remover da lista.\n");
				scanf("%d",&valor);
				remover(l1,valor);
				break;
			}
			case 6:{
				system("cls");
				if(l1->quantidade==0){
					printf("a lista esta vazia\n");
				}else{
					removePrimos(l1);
				}
				break;
			}
			case 7:{
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
	reg->antes=NULL;
	return reg;
}

void adicionarInicio(lista *l1, int valor){
	registro *reg, *aux;
	
	reg = alocar_registro();
	aux = alocar_registro();
	
	reg->valor=valor;
	
	if(l1->inicio==NULL){
		l1->inicio=reg;
			if(l1->fim==NULL){
				l1->fim=reg;
			}else{
				aux = l1->fim;
				while(aux->antes!=NULL){
					aux=aux->antes;
				}
				aux->antes=reg;
				reg->proximo=aux;
			}
		l1->quantidade++;
	}else{
		aux = l1->inicio;
		reg->proximo=aux;
		aux->antes=reg;
		l1->inicio=reg;
		l1->quantidade++;
	}	
}

void adicionarFim(lista *l1, int valor){
	registro *reg, *aux;
	
	reg = alocar_registro();
	aux = alocar_registro();
	
	reg->valor=valor;
	
	if(l1->fim==NULL){
		l1->fim=reg;
		if(l1->inicio==NULL){
			l1->inicio=reg;
		}else{
			aux=l1->inicio;
			while(aux->proximo!=NULL){
				aux=aux->proximo;
			}
			aux->proximo=reg;
			reg->antes=aux;
		}
		l1->quantidade++;
	}else{
		aux=l1->fim;
		aux->proximo=reg;
		reg->antes=aux;
		l1->fim=reg;
		l1->quantidade++;
	}
}

void mostrarIndo(lista *l1){
	registro *reg;
	
	reg = alocar_registro();
	
	if(l1->quantidade==0){
		printf("a lista esta vazia.\n");
	}else{
		reg = l1->inicio;
	
		printf("%d/",reg->valor);
	
		while(reg->proximo!=NULL){
			reg = reg->proximo;
			printf("%d/",reg->valor);
		}
	}
	
	printf("\n");
	
	printf("quantidade de elementos = %d",l1->quantidade);
	
	printf("\n");
}

void mostrarVindo(lista *l1){
	registro *reg;
	reg = alocar_registro();
	
	if(l1->quantidade==0){
		printf("a lista esta vazia.\n");
	}else{
		reg = l1->fim;
		printf("%d/",reg->valor);
		while(reg->antes!=NULL){
			reg = reg->antes;
			printf("%d/",reg->valor);
		}	
	}
	

	
	printf("\n");
	
	printf("quantidade de elementos = %d",l1->quantidade);
	
	printf("\n");
}

void remover(lista *l1, int valor){
	registro *reg, *aux;
	
	reg = alocar_registro();
	aux = alocar_registro();
	
	int qtdValor = l1->quantidade;
	
	if(l1->quantidade==0){
		printf("a lista esta vazia.\n");
	}else{
		reg=l1->inicio;
		if(reg->valor==valor){
			l1->inicio=reg->proximo;
			l1->quantidade--;
		}
		while(reg->proximo!=NULL){
			aux=reg;
			reg=reg->proximo;
			if(reg->valor==valor){
				aux->proximo=reg->proximo;
				reg->proximo->antes=aux;
				l1->quantidade--;
			}
		}
	}
	
	if(qtdValor==l1->quantidade){
		printf("valor %d nao encontrado.\n",valor);
	}else{
		printf("valor %d removido.\n",valor);
	}
}

void removePrimos(lista *l1){
	registro *reg, *aux;
	
	reg = alocar_registro();
	aux = alocar_registro();
	
	reg = l1->inicio;
	
	if(verificaPrimo(reg->valor)==true){
		remover(l1,reg->valor);
	}
	
	while(reg->proximo!=NULL){
			aux = reg;
			reg = reg->proximo;			
			if(verificaPrimo(reg->valor)==true){
				if(reg->proximo==NULL){
					int valor = reg->valor;
					aux->proximo=NULL;
					l1->fim=aux;
					printf("valor %d removido\n",valor);
					l1->quantidade--;
				}else{
					remover(l1,reg->valor);
				}	
			}
	}
}

bool verificaPrimo(int valor){
	if(valor==2||valor==3||valor==5||valor==7){
		return true;
	}else{
		if(valor%2==0||valor==1){
			return false;
		}else if(valor%3==0){
			return false;
		}else if(valor%5==0){
			return false;
		}else if(valor%7==0){
			return false;
		}
		return true;
	}
}













