#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

char pilha[1000];
int tp = 0;

void push(char x);
char pop();
char stackpop();
int empty();
int tamanho();

int main(){
    char palavra[1000];
    int  vet_diam[1000];
    int i,j,n=0;
    int cont_diamant=0;
    int cont_MaiorQ = 0;
    int cont_MenorQ = 0;
    int paridade_Par = 0;


    printf("Digite a quantidade de testes: ");
    scanf("%d", &n);
    
    for(j=0; j<n;j++){
        printf("\n Digite a palavra para extração:");
        __fpurge(stdin);
        fgets(palavra,100,stdin);
        palavra[strlen(palavra)-1] = '\0';
        for(i = 0; i <strlen(palavra); i++){
            if(palavra[i] == '>' || palavra[i] == '<'){
                push(palavra[i]);
            }
        }

        while(tamanho() != 0){
            if(pop() == '>'){
                cont_MaiorQ++;
            }else{
                cont_MenorQ++;
            }
        }

        if(cont_MaiorQ < cont_MenorQ){
            cont_diamant = cont_MaiorQ;
        }else if (cont_MaiorQ > cont_MenorQ){
            cont_diamant = cont_MenorQ;
        }else{
            cont_diamant = cont_MaiorQ;
        }

        vet_diam[j]=cont_diamant;
       
       cont_diamant = 0;
       cont_MaiorQ = 0;
       cont_MenorQ = 0;
    }
    for(i=0;i<n;i++){
        printf("%d\n",vet_diam[i]);
    }
        

    return 0;
}

void push(char x){
    if(tp == 50){
        printf("Pilha cheia");
    }else{
        pilha[tp] = x;
        tp++;
    }
}

char pop(){
    char desempilhado;
    if(tp == 0){
        printf("Pilha vazia");
    }else{
        tp--;
        desempilhado = pilha[tp];
        return desempilhado;
    }
}

char stackpop(){
    return pilha[tp - 1];
}

int empty(){
    if(tp =0){
        return 1;
    }else{
        return 0;
    }
}

int tamanho(){
    return tp;
}