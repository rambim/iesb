#include <stdio.h>
#include <stdlib.h>

typedef struct Data /*de nascimento*/
{
    int dia, mes, ano;
} Data;

/*
Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até 10 pessoas. 
Cada pessoa deve ser representada por uma struct dentro de um vetor. 
A data de nascimento também deve ser uma struct.
O nome e a altura de cada pessoa devem ser informados pelo teclado.
A geração da data de nascimento deve ser feita aleatoriamente através da função abaixo
*/

void CriaData(Data *D)
{
    D->mes = 1 + (rand() % 12);
    D->ano = 1950 + (rand() % 49);
    D->dia = 1 + (rand() % 30);
}

/*
    O programa deve, na tela de abertura, apresentar opções para:
    inserir um nome;
    listar todos os nomes e respectivas alturas;
    listar os nomes das pessoas que nasceram antes de uma certa data fornecida.
Cada uma destas opções deve ser implementada em uma função separada.
Para realizar o exercício, utilize como base o programa apresentado abaixo.
*/

typedef struct
{
    long int matricula;
    float altura;
    Data nascimento;
} Pessoa;

void ImprimeTelaDeOpcoes();
int EscolheOpcao();
void LePessoaDeTeclado(Pessoa *individuo);
void AdicionaPessoa(Pessoa *povo, Pessoa p, int qtdPessoas);
void ImprimeTodasAsPessoas(Pessoa *povo, int qtdPessoas);

int main()
{
    Pessoa povo[10];
    Pessoa p;
    int opcao, qtdPessoas = 0;
    Data dia;

    ImprimeTelaDeOpcoes();
    do
    {
        opcao = EscolheOpcao();
        if (opcao == 1)
        {
            LePessoaDeTeclado(&p);
            printf("Pessoa -> %d %d %d",p.nascimento.dia,p.nascimento.mes,p.nascimento.ano);
            AdicionaPessoa(povo, p, qtdPessoas);
            qtdPessoas += 1;
        }
        if (opcao == 2)
        {
            ImprimeTodasAsPessoas(povo, qtdPessoas);
        }
        /*if (opcao == 3)
        {
            LeDataDeTeclado(&dia);
            ImprimeMaisVelhos(povo, qtdPessoas, dia);
        }*/
    } while (opcao != 4);
}

int EscolheOpcao()
{
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

void ImprimeTelaDeOpcoes()
{
    printf("Digite:\n1-Para inserir uma pessoa\n2-Para listar nomes e respectivas alturas\n3- Para listar os nomes das pessoas que nasceram antes de uma certa data\n");
}

void LePessoaDeTeclado(Pessoa *individuo)
{
    printf("Matricula: ");
    scanf("%ld", &individuo->matricula);
    printf("altura: ");
    scanf("%f", &individuo->altura);

    CriaData(&(individuo->nascimento));
    printf(" \n****** %d\n", individuo->nascimento.dia);
}

void AdicionaPessoa(Pessoa *povo, Pessoa p, int qtdPessoas)
{
    povo[qtdPessoas].matricula = p.matricula;
    povo[qtdPessoas].altura = p.altura;
    povo[qtdPessoas].nascimento = p.nascimento;
}

void ImprimeTodasAsPessoas(Pessoa *povo, int qtdPessoas)
{
    for (int i = 0; i < qtdPessoas; i++)
    {

        printf("\nMatricula: %ld\nAltura: %f\n", (povo[i]).matricula, (povo[i]).altura);
        printf("Data de nascimento: %d/%d/%d\n", povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
    }
}