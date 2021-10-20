/*

Faça um programa que solicite ao usuário um número N e leia do usuário a informação de N carros. Cada carro é composto por 
um numero de registro e um ano de fabricação.

Após lido os N carros, mostre na tela o carro mais novo e qual dos carros possui numero de identificação maior que 10.


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct carro
{
    int ano_fabricacao;
    int numero_registro;
}carro;

int main()
{
    int n,indice_mais_novo=0;

    carro * vet_carros;


    printf("\nDigite a quantidade de carros (n): ");
    scanf("%d",&n);

    vet_carros = (carro *) malloc(sizeof(carro)*n);

    preenche_vetor_carros(vet_carros,n);

    indice_mais_novo = mais_novo(vet_carros,n);
    printf("\n O carro mais novo e o carro do indice %d ano %d",indice_mais_novo,vet_carros[indice_mais_novo].ano_fabricacao);
    free(vet_carros);

    printf("\n");
    return 0;
}

void preenche_vetor_carros( carro * vet_carros, int qtd_carros)
{
    int i;

    for(i=0;i<qtd_carros;i++)
    {
        printf("\nDigite o ano de fabricacao: ");
        scanf("%d",&vet_carros[i].ano_fabricacao);
        printf("\nDigite o numero de registro: ");
        scanf("%d",&vet_carros[i].numero_registro);
    }   
}

int mais_novo(carro * vet_carros, int qtd_carros)
{
    int retorno=0;
    int maior_ano=0;
    int i;

    for(i=0;i<qtd_carros;i++)
    {
        if (vet_carros[i].ano_fabricacao > maior_ano)
        {
            maior_ano = vet_carros[i].ano_fabricacao;
            retorno = i;
        }
    }
    return retorno;
}

void mostrar_maior_que_10 (carro * vet_carros , int qtd_carros)
{
    int i;

    for(i=0;i<qtd_carros;i++)
    {
        if (vet_carros[i].numero_registro >=10)
        {
            printf("\n Veiculo %d ano %d",vet_carros[i].numero_registro,vet_carros[i].ano_fabricacao);
        }
    }
}


