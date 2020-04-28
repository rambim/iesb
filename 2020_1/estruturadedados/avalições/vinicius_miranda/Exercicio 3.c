#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct Lista{
	
	struct Registro* primeiro_elemento;
	
}Lista;

typedef struct Registro{
	
	int valor_elemento;
	struct Registro* proximo_elemento;
	
}Registro;

Lista* criar_lista1(void){
	
	Lista* criar_lista1 = (Lista*)malloc(sizeof(Lista));
	criar_lista1 -> primeiro_elemento = NULL;
	
	return criar_lista1;
}

Registro* criar_registro1(void){
	
	Registro* criar_registro1 = (Registro*)malloc(sizeof(Registro));
	criar_registro1 -> proximo_elemento = NULL;
	criar_registro1 -> valor_elemento = 0;
	
	return criar_registro1;
}


void adicionar_elemento(Lista* lista1, int valor_desejado){
	
	Registro* x = criar_registro1();
	x -> valor_elemento = valor_desejado;
	
	if(lista1->primeiro_elemento == NULL){
		lista1->primeiro_elemento = x;
	}
	else{
		Registro* aux = lista1->primeiro_elemento;
		
		while(aux->proximo_elemento != NULL){
			aux = aux->proximo_elemento;
		}
		aux->proximo_elemento = x;
	}
	
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
					printf("\nValor removido\n\n");
					
			}
		}
	}
}
	


void mostrar(Lista* lista1){
	
	if(lista1->primeiro_elemento != NULL){
		
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
		printf("A Lista está vazia\n");
	}
	
}

void buscar_ant_suc(Lista* lista1, int valor_escolhido){
	
    if(lista1->primeiro_elemento == NULL){
        printf("\nNão há Sucessores nem Antecessores, pois a lista está vazia.\n");
        printf("\n");
    }
    
	else{
	
        Registro* aux = lista1->primeiro_elemento;
        Registro* ant = NULL;
        Registro* suc = aux->proximo_elemento;
        
        while(aux->valor_elemento != valor_escolhido){
           ant = aux;
           aux = aux->proximo_elemento;
           suc = aux->proximo_elemento;
        }
		
        if(aux->proximo_elemento == NULL){ 
        	printf("\nAntecessor = %d\n", ant->valor_elemento);
        	printf("Sucessor não existente\n");
        	printf("\n");
		}
		if(ant == NULL){
			printf("\nNão existe antecessor\n"); 
			printf("Sucessor = %d\n", suc->valor_elemento);
			printf("\n");
		}
		if(ant != NULL && suc != NULL){
			printf("\nAntecessor = %d\n", ant->valor_elemento);
			printf("Sucessor = %d\n", suc->valor_elemento);
			printf("\n");
		}
		
    }
}

void menu(Lista* lista1){
	
	int valor_adicionar=0, opcoes=0, valor_escolhido=0;
	
do{
	printf("0 - Para sair\n");
		printf("1 - Para Adicionar\n");
			printf("2 - Para Remover\n");
				printf("3 - Para mostrar\n");
					printf("4 - Para Buscar Antecessor e Sucessor\n");
		
	printf("Digite a sua Opção: ");
	scanf("%d", &opcoes);
	printf("\n");
	
	switch(opcoes){
		
		case 0:
			printf("Você está saindo do programa...\n");
			break;
			
		case 1:
			printf("Digite o Valor que Você Deseja Adicionar: ");
			scanf("%d", &valor_adicionar);
			printf("\n");
			adicionar_elemento(lista1, valor_adicionar);
			break;
			
		case 2:
			printf("Digite o Valor para Remover: ");
			scanf("%d", &valor_escolhido);
			remover_elemento_especifico(lista1,valor_escolhido);
			break;
		
		case 3: 
			mostrar(lista1);
			break;
			
		case 4:
			printf("Digite o Valor que você deseja buscar seu Antecessor e Sucessor: ");
			scanf("%d", &valor_escolhido);
			buscar_ant_suc(lista1, valor_escolhido);
			break;
			
		default:
			printf("Opção Não Existente");
	}
	
}while(opcoes!=0);

}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	Lista* lista1 = criar_lista1();
	
	menu(lista1);

		return 0;
}
