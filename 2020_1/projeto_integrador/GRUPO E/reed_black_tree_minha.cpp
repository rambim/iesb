#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<locale.h>
#define RUBRO 1
#define NEGRO 2

typedef struct arvore{
	int num;
	int cor;
	struct arvore * pai;
	struct arvore * esquerda;
	struct arvore * direita;
}arvore;

arvore * aloca_arvore();

void menu(arvore * a);
void insere_arvore(arvore * a,int x);
void mostrar_arvore(arvore * a);

int main(){
	
	arvore * a;
	a = aloca_arvore();
	
	menu(a);
	
	getch();
}

arvore * aloca_arvore(){
	arvore * novo;
	novo =(arvore*)malloc(sizeof(arvore));
	novo->num = 0;
	novo->cor = 0;
	novo->pai = NULL;
	novo->esquerda = NULL;
	novo->direita = NULL;
	return novo;
}

void insere_arvore(arvore * a,int x){
	arvore * novo;
	novo = aloca_arvore();
	novo->num = x;
	novo->cor = NEGRO;
	
	if (a->num==0){
		a->num = x;	
		printf("chegou.1");	
	}else{
		printf("chegou.2");
		if(x>a->num){
			if(a->direita==NULL){
				printf("chegou.3");
				novo->pai=a;
				a->direita=novo;
			}else{
				insere_arvore(a->direita, x);
			}
		}else if(x<a->num){
			printf("chegou.4");
			if(a->esquerda==NULL){
				novo->pai=a;
				a->esquerda=novo;
			}else{
				insere_arvore(a->esquerda, x);
			}
		}else{
			printf("Número já inserido");
		}
		
	}
}

void mostrar_arvore(arvore * a){
	printf (" %d ", a->num);
	if (a->esquerda!=NULL) {      
		mostrar_arvore(a->esquerda);       
		//printf (" %d ", a->num);
    }
	if(a->direita!=NULL){
		mostrar_arvore(a->direita);
		//printf (" %d ", a->num);
	}
}

void menu(arvore * a){
	setlocale(LC_ALL, "Portuguese");
	int op, num;
	
	do{
		system("cls");
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Mostrar\n");
		printf("4 - Sair\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("Qual número deseja incluir na árvore?\n");
				scanf("%d", &num);
				
				insere_arvore(a,num);
				
				getch();
			break;
			case 2:
			break;
			case 3:
				
				mostrar_arvore(a);
				
				getch();
			break;
			case 4:
				printf("Saindo...");
			break;
			default:
				printf("Opção inválida!");
				getch();
			break;
		}
		
	}while(op!=4);
	
	
	getch();
}
