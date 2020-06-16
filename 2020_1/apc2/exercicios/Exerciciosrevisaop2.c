

/*


Faca um programa para armazenar um livro de receitas e:
•Crie um vetor de 5 receitas, que deve ter nome (maximo 25 letras), 
quantidade de ingredientes e ingredientes.
•Para cada receita, leia seu nome e a quantidade de ingredientes.  
Entao crie e leia o vetor de ingredientes, 
sendo que cada ingrediente contem nome e quantidade.
•Procure receita por nome, mostrando seus ingredientes se encontrar.  
Se nao encontrar, informe ao usuario. 
Repita o processo ate digitar uma string vazia.


*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct receita
{
    char nome_receita[25];
    char * nome_ingredientes[25];
    int * qtd_ingredientes;
}receita;

int main()
{
    receita receitas[5];    
    int qtd_receitas=0;

    return 0;
}

void preenche_receita(receita * a)
{
    int qtd_ingredientes_receita=0;
    printf("\nQual o nome da receita?:  ");
    __fpurge(stdin);
    fgets(a->nome_receita,25,stdin);
    a->nome_receita[strlen(a->nome_receita)-1] = '\0';
    printf("\n Quantos ingredientes sua receita possui?: ");
    scanf("%d",&qtd_ingredientes_receita);




}

