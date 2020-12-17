#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct endereco{
    char bairro[15];
    char rua[20];
    char cidade[19];
    char cep[13];
    char estado[10];
}endereco;



typedef struct cadastro{
    char nome[50];
    char rg[10];
    char cpf[11];
    char civil[20];
    char telefone[13];
    int idade;
    char sexo[9];
    float salario;
    endereco endereco;
}cadastro;


int main()
{
   cadastro pessoa [5];
   int i=0;

   for(i=0;i<5;i++){
    printf("seu nome \n");
    scanf("%s", pessoa[i].nome);

    printf("seu salario\n ");
    scanf("%f", &pessoa[i].salario);

    printf("seu rg\n ");
    scanf("%s", pessoa[i].rg);

    printf("seu cpf\n ");
    scanf("%s", pessoa[i].cpf);

    printf("seu estado civil\n");
    scanf("%s", pessoa[i].civil);

    printf("seu telefone\n ");
    scanf("%s", pessoa[i].telefone);

    printf("sua idade\n ");
    scanf("%d", &pessoa[i].idade);

    printf("seu sexo\n");
    scanf("%s", pessoa[i].sexo);
    

   printf("sua rua\n");
    scanf("%s", pessoa[i].endereco.rua);

   printf("seu bairro\n");
   scanf("%s", pessoa[i].endereco.bairro);

   printf(" seu cep\n ");
    scanf("%s", pessoa[i].endereco.cep);

   printf("sua cidade\n");
   scanf("%s", pessoa[i].endereco.cidade);

   printf("seu estado\n");
    scanf("%s", pessoa[i].endereco.estado);
   }

   
   int maior = 0, j=0;
    for(i=0;i<5;i++){
        if(maior< pessoa[i].idade){
            maior = pessoa[i].idade;
            j=i;
        }
    }
    printf("a pessoa mais velha eh o %s com %d anos\n", pessoa[j].nome, pessoa[j].idade);
    
    for(i=0;i<5;i++){
        if(strcmp(pessoa[i].sexo ,"masculino")==0){
            printf("pessoas do sexo masculino: %s\n",pessoa[i].nome);
        }
    }
    for(i=0;i<5;i++){
        if(pessoa[i].salario>1000.00){
            printf("o %s tem salario de %f \n", pessoa[i].nome, pessoa[i].salario);

        }
    }
    char rgaux[10];

    printf("qual rg voce deseja buscar?\n");
    scanf("%s", rgaux);

    for(int i=0;i<5;i++){
        if(strcmp(rgaux, pessoa[i].rg)== 0){
           printf("o %s tem o rg que estava sendo procurado", pessoa[i].nome);
        }
    }
}
