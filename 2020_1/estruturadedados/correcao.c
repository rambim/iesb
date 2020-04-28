//Implemente uma LISTA LIGADA e adicione uma opção que BUSQUE um número dentro da lista e mostre o valor 
//do registro imediatamente ANTERIOR e do imediatamente POSTERIOR.
#include<stdio.h>
#include<stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

lista * aloca_lista(){
    lista * bow;
    bow = (lista*)malloc(sizeof(lista));
    bow-> qtd = 0;
    bow -> inicio = NULL;
    return bow;
}

elemento * aloca_elemento(){
    elemento * bow;
    bow = (elemento*)malloc(sizeof(elemento));
    bow -> valor = 0;
    bow -> prox = NULL;
    return bow;
}

void inserir_lista(lista * l1 , int x){
    elemento * aux , * novo;
    novo = aloca_elemento();
    novo -> valor = x;
    if(l1->inicio == NULL){
        l1->inicio = novo;
    }
    else{
        aux = l1->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux-> prox = novo;
    }
    l1->qtd++;
}

void mostrar_lista(lista * l1){
    elemento * aux;
    
    if(l1->inicio == NULL){
        printf("\nLista Vazia\n");
    }
    else{
        aux = l1->inicio;
        while(aux != NULL){
            printf("%d \n", aux->valor);
            aux = aux->prox;
        }
    }
}

void buscar_lista(lista * l1 , int x){
    elemento * ant , * aux ;

    if(l1->inicio == NULL){
        printf("\nLista Vazia\n");
    }
    else{
        aux = l1->inicio;
        ant = aux;
        while(aux -> valor != x ){
            
            ant = aux;
            aux = aux-> prox;
            
            }
        }
        if(aux-> valor != x ){
            printf("\nValor não encontrado");
        }       
        else{
            printf("\nValor selecionado: %d", x);
            
                if(ant->valor == aux->valor){
                    printf("\nValor anterior: Vazio");      
                }
                else{
                    printf("\nValor anterior: %d", ant->valor);
                }
                if(aux->prox != NULL){
                     printf("\nValor posterior: %d", aux->prox->valor);
                }
                else{
                    printf("\nValor posterior: Vazio");           
                }
            }
}
void menu(lista * l1){
    int i , l , d ;

    do{
        printf("\n1-Inserir na lista"
               "\n2-Mostrar lista"
               "\n3-Buscar na lista"
               "\n4-Sair");
            scanf("%d", &i);
        switch(i){
            case 1:
                do{
                    printf("\nDigite o valor a ser inserido:");
                        scanf("%d", &l);
                    inserir_lista(l1,l);
                    printf("\nContinuar a inserir?"
                            "\n1- Sim | 2- Nao");
                        scanf("%d",&d);        
                }while(d!=2);
            break;
            case 2:
                mostrar_lista(l1);
            break;
            case 3:
                do{
                    printf("\nQual Num deseja buscar? : ");
                        scanf("%d", &l);
                    buscar_lista(l1 ,l);    
                    printf("\nBuscar novamente?"
                            "\n1- Sim | 2- Nao");
                        scanf("%d", &d);   
                }while(d!=2);   
            break;         
        }//switch        
    }while(i != 4);

}

int main(){    
    lista * l1 = aloca_lista();     
    menu(l1);
    return 0;
}