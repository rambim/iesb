#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//QUESTAO 1(a)

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
void push(lista *l1, int valor);
char pop(lista *l1);
bool empty(lista *l1);
int stackpop(lista *l1);

int main(){
	
	lista *pilha, *pilha2;
	
	pilha2 = alocar_lista();
	
	pilha = alocar_lista();

	char *expressao;
	
	expressao = (char *)malloc(sizeof(char)*400);
	
	scanf("%s",expressao);	

	for(int i=0; i<strlen(expressao); i++){
		if(expressao[i]=='A'){
			push(pilha,'A');
		}else if(expressao[i]=='B'){
			push(pilha,'B');
		}else if(expressao[i]=='C'){
			int valor = i;
			i++;
			while(valor>0){
				char letra = pop(pilha);
				if(expressao[i]!=letra){
					push(pilha2,1);
				}
				
				if(expressao[i]==NULL){
					push(pilha2,1);
					break;
				}	
				i++;
				valor--;
			}
			i--;
		}else{
			push(pilha2,1);
			break;
		}
	}
	
	if(empty(pilha2)==true&&empty(pilha)==true){
		printf("e da forma xCy");
	}else{
		printf("nao e da forma xCy");
	}	
	return 0;
}

lista *alocar_lista(){
	lista *l1;
	l1 = (lista *)malloc(sizeof(lista));
	l1->quantidade=0;
	l1->inicio=NULL;
	return l1;
}

registro *alocar_registro(){
	registro *reg;
	reg = (registro *)malloc(sizeof(registro));
	reg->valor=0;
	reg->proximo=NULL;
	return reg;
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
		aux = l1->inicio;
		reg->proximo=aux;
		l1->inicio=reg;
		l1->quantidade++;
	}
}

char pop(lista *l1){	
	if(l1->quantidade>0){
		char valor = l1->inicio->valor;

		l1->inicio=l1->inicio->proximo;
	
		l1->quantidade--;
	
		return valor;
	}else{
		return 'Z';
	}
}

bool empty(lista *l1){
	if(stackpop(l1)==-1){
		return true;
	}else{
		return false;
	}
}

int stackpop(lista *l1){
	if(l1->inicio==NULL){
		return -1;
	}else{
		return l1->inicio->valor;
	}
}







