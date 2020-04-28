#include<stdio.h>
#include<stdlib.h>

//QUESTAO 2 

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

int cartaBase;
int numCartas;
lista *descartadas, *remanescentes, *saidaDescartadas, *saidaRemanescentes;

lista *alocar_lista();
registro *alocar_registro();
void push(lista *l1, int valor);
void pushFim(lista *l1, int valor);
void mostrarIndo(lista *l1);
void mostrarVindo(lista *l1);
int pop(lista *l1);
void mostrarCartasRetiradas(lista *l1);
void mostrarCartasRestantes(lista *l1);
bool empty(lista *l1);
int stackpop(lista *l1);
int popFim(lista *l1);
int stackpopFim(lista *l1);

int main(){

	scanf("%d",&numCartas);
	
	saidaDescartadas = alocar_lista();
	saidaRemanescentes = alocar_lista();
	
	while(numCartas!=0){

		descartadas = alocar_lista();
		remanescentes = alocar_lista();
		
		int cartaDescartada;

		int cartaBase=0;

		for(int i=numCartas; i>0; i--){
			push(remanescentes,i);
		}
	
		while(numCartas!=1){
			pushFim(descartadas,pop(remanescentes));
			cartaBase = pop(remanescentes);
			if(remanescentes->inicio==NULL){
				break;
			}
			pushFim(remanescentes,cartaBase);
			numCartas--;
		}
		
		while(empty(descartadas)==false){
			push(saidaDescartadas,pop(descartadas));
		}
		
		push(saidaDescartadas,0);
		
		push(saidaRemanescentes,cartaBase);

		scanf("%d",&numCartas);	
		free(descartadas);
		free(remanescentes);
	}
	
	system("cls");
	
	pop(saidaDescartadas);
	
	while(saidaDescartadas->quantidade!=0){
		printf("Discarded cards:");
		while(stackpopFim(saidaDescartadas)!=0&&stackpop(saidaDescartadas)!=-1){
			if(saidaDescartadas->fim->antes->valor==0){
				printf(" %d",popFim(saidaDescartadas));
			}else{
				printf(" %d,",popFim(saidaDescartadas));
			}	
		}
		printf("\n");
		if(stackpopFim(saidaDescartadas)==0){
			popFim(saidaDescartadas);
		}
		printf("Remaining card: %d",popFim(saidaRemanescentes));
		if(saidaDescartadas->quantidade!=0){
			printf("\n");
		}
	}
		
	return 0;
};

int stackpop(lista *l1){
	if(l1->inicio==NULL){
		return -1;
	}else{
		return l1->inicio->valor;
	}
}

bool empty(lista *l1){
	if(l1->quantidade==0){
		return true;
	}else{
		return false;
	}
}

void mostrarCartasRestantes(lista *l1){
	if(l1->inicio==NULL){
		printf("sem cartas restantes\n");
	}else{
		printf("Remaining card: %d",l1->inicio->valor);	
	}
}


void mostrarCartasRetiradas(lista *l1){
	registro *reg;
	
	reg = alocar_registro();
	
	reg = l1->inicio;
	
	printf("Discarded cards:");
	if(l1->inicio!=NULL){
		printf(" %d,",reg->valor);
	
		while(reg->proximo!=NULL){
			reg=reg->proximo;
			printf(" %d,",reg->valor);
		}	
	}else{
		printf("nao possui cartas\n");
	}
	printf("\n");		
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

void push(lista *l1, int valor){
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

void pushFim(lista *l1, int valor){
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

}

void mostrarVindo(lista *l1){
	registro *reg;
	reg = alocar_registro();
	
	if(l1->quantidade==0){
		printf("a lista esta vazia.\n");
	}else{
		reg = l1->fim;
		printf("Discarded cards:");
		printf(" %d,",reg->valor);
		while(reg->antes!=NULL){
			reg = reg->antes;
			if(reg->antes==NULL){
				printf(" %d",reg->valor);
				break;
			}			
			printf(" %d,",reg->valor);
		}	
	}
	printf("\n");
}

int pop(lista *l1){	
	if(l1->quantidade==0){
		return 0;
	}else{
		int valor = l1->inicio->valor;
		l1->inicio=l1->inicio->proximo;
		l1->quantidade--;
		return valor;
	}
}

int popFim(lista *l1){	
	if(l1->quantidade==0){
		return 0;
	}else{
		int valor = l1->fim->valor;
		l1->fim=l1->fim->antes;
		l1->quantidade--;
		return valor;
	}
}

int stackpopFim(lista *l1){
	if(l1->fim==NULL){
		return -1;
	}else{
		return l1->fim->valor;
	}
}













