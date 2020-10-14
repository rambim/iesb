#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct funcionario
{
    int idade;
    long int cpf;
    char nome_completo[30];
    long int telefone;
    

} funcionario;


void preencher_vetor_funcionarios(funcionario *vet, int qtd);
void mostrar_funcionarios ( funcionario * vet, int tam);


int main()
{
    int qtd_funcionarios;

    funcionario *vet;

    printf("\n Quantos funcionarios deseja alocar? ");
    scanf("%d", &qtd_funcionarios);

    vet = (funcionario *)malloc(sizeof(funcionario) * qtd_funcionarios);
    preencher_vetor_funcionarios(vet,qtd_funcionarios);
    printf("\n Mostrando funcionarios: ");
    mostrar_funcionarios(vet,qtd_funcionarios);
    printf("\n");
    return 0;
}


void preencher_vetor_funcionarios(funcionario *vet, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++)
    {
        printf("\n Digite seu nome: ");
        __fpurge(stdin);
        fgets(vet[i].nome_completo, 30, stdin);
        vet[i].nome_completo[strlen(vet[i].nome_completo)-1] = '\0';
        printf("\n Digite sua idade");
        scanf("%d", &vet[i].idade);
        printf("\n Digite seu telefone: ");
        scanf("%ld", &vet[i].telefone);
        printf("\n Digite seu CPF: ");
        scanf("%ld", &vet[i].cpf);
    }
}


void mostrar_funcionarios ( funcionario * vet, int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\n Nome    : %s ",vet[i].nome_completo);
        printf("\n Telefone: %ld",vet[i].telefone);
        printf("\n CPF     : %ld",vet[i].cpf );
        printf("\n Idade   : %d",vet[i].idade );
        printf("\n");
    }
}