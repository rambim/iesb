#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct Lista{
	
	struct Registro* primeiro_elemento;
	struct Registro* ultimo_elemento;
	int quantidade_elementos;
	
}Lista;

typedef struct Registro{
	
	int valor_elemento;
	struct Registro* proximo_elemento;
	struct Registro* elemento_anterior;
	
}Registro;

Lista* criar_lista1(void){
	
	Lista* criar_lista1 = (Lista*)malloc(sizeof(Lista));
	criar_lista1 -> primeiro_elemento = NULL;
	criar_lista1 -> ultimo_elemento = NULL;
	
	return criar_lista1;
}

Registro* criar_registro1(void){
	
	Registro* criar_registro1 = (Registro*)malloc(sizeof(Registro));
	criar_registro1 -> proximo_elemento = NULL;
	criar_registro1 -> elemento_anterior = NULL;
	criar_registro1 -> valor_elemento = 0;
	
	return criar_registro1;
}


void adicionar_elemento_comeco(Lista* lista1, int valor_desejado){
	
	Registro* novo_elemento = criar_registro1();
	Registro* aux;
	novo_elemento -> valor_elemento = valor_desejado;
	
	if(lista1->quantidade_elementos == 0){
		lista1->primeiro_elemento = novo_elemento;
		lista1->ultimo_elemento = novo_elemento;
	}
	else{
		aux = lista1->primeiro_elemento;
		aux->elemento_anterior = novo_elemento;
		novo_elemento->proximo_elemento = aux;
		lista1->primeiro_elemento = novo_elemento;
	}
	
	lista1->quantidade_elementos = lista1->quantidade_elementos + 1;
	
}

void adicionar_elemento_final(Lista* lista1, int valor_desejado){
	
	Registro* novo_elemento = criar_registro1();
	Registro* aux;
	novo_elemento -> valor_elemento = valor_desejado;
	
	if(lista1->quantidade_elementos == 0){
		lista1->primeiro_elemento = novo_elemento;
		lista1->ultimo_elemento = novo_elemento;
	}
	else{
		aux = lista1->ultimo_elemento;
		aux->proximo_elemento = novo_elemento;
		novo_elemento->elemento_anterior = aux;
		lista1->ultimo_elemento = novo_elemento;
	}
	
	lista1->quantidade_elementos = lista1->quantidade_elementos + 1;
	
}

void remover_elemento_especifico(Lista* lista1, int valor_desejado){
	
	if(lista1->primeiro_elemento != NULL){
		Registro* ant = NULL;
		Registro* aux = lista1->primeiro_elemento;
		
		if(aux->valor_elemento == valor_desejado){
			lista1->primeiro_elemento = aux->proximo_elemento;
			free(aux);
		}
		else{
			while(aux != NULL){
				if(aux->valor_elemento == valor_desejado){
					break;
				}
				ant = aux;
				aux = aux->proximo_elemento;
			}
			if(aux == NULL){
				printf("Valor não Encontrado\n");
			}
			else{
				
					ant->proximo_elemento = aux->proximo_elemento;
					free(aux);
					printf("\nValor removido\n");
					
			}
		}
	}
}

int analisar_primo(int valor_desejado){
	
	int divisor, resultado=0;
	
	for(divisor = 2; divisor<valor_desejado; divisor++){
		if(valor_desejado%divisor == 0){
			return 0;
	}
}
	
	return 1;
	
}

void remover_primos(Lista* lista1){
	
	Registro* aux;
	int valor_removido, apaga=0;
	
	if(lista1->primeiro_elemento == NULL){
		printf("Não há valores para serem removidos\n\n");
	}
	else{
		aux = lista1->primeiro_elemento;
		while(aux != NULL){
			apaga = 0;
			if(analisar_primo(aux->valor_elemento)){
				valor_removido = aux->valor_elemento;
				apaga = 1;
		}
			aux = aux->proximo_elemento;
			if(apaga == 1){
				remover_elemento_especifico(lista1, valor_removido);
			}
	 	}
	}
}
	

void mostrar(Lista* lista1){
	
	if(lista1->quantidade_elementos != 0){
		
		Registro* valor_apresentado = lista1->primeiro_elemento;
		printf("Valores da Lista:\n");
		do{
			printf("%d", valor_apresentado->valor_elemento);
			valor_apresentado = valor_apresentado->proximo_elemento;
			printf("\n");
			
		}while(valor_apresentado != NULL);
		printf("\n");
	}
	else{
		printf("A Lista está vazia\n\n");
	}
	
}


void menu(Lista* lista1){
	
	int valor_adicionar=0, opcoes=0, valor_escolhido=0;
	
do{
	printf("0 - Para sair\n");
		printf("1 - Para Adicionar elemento no começo\n");
			printf("2 - Para Adicionar elemento no final\n");
				printf("3 - Para Remover um Valor Específico\n");
					printf("4 - Para mostrar\n");
						printf("5 - Para Remover os Primos\n");
		
	printf("Digite a sua Opção: ");
	scanf("%d", &opcoes);
	printf("\n");
	
	switch(opcoes){
		
		case 0:
			printf("Você está saindo do programa...\n");
			break;
			
		case 1:
			printf("Digite o Valor que Você Deseja Adicionar no Começo: ");
			scanf("%d", &valor_adicionar);
			printf("\n");
			adicionar_elemento_comeco(lista1, valor_adicionar);
			break;
			
		case 2:
			printf("Digite o Valor que Você Deseja Adicionar no Final: ");
			scanf("%d", &valor_adicionar);
			printf("\n");
			adicionar_elemento_final(lista1, valor_adicionar);
			break;
			
		case 3:
			printf("Digite o Valor para Remover: ");
			scanf("%d", &valor_escolhido);
			remover_elemento_especifico(lista1,valor_escolhido);
			break;
		
		case 4: 
			mostrar(lista1);
			break;
			
		case 5:
			remover_primos(lista1);
			break;
			
		default:
			printf("Opção Não Existente\n\n");
			break;
	}
	
}while(opcoes!=0);

}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	Lista* lista1 = criar_lista1();
	
	menu(lista1);

		return 0;
}
