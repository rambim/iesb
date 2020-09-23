#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int dia, mes, ano;
} Data;

/*
Crie um programa que permita armazenar o matricula, a altura e da data de nascimento de até 10 pessoas. 

Cada pessoa deve ser representada por uma struct dentro de um vetor. 

A data de nascimento também deve ser uma struct.

A matricula e a altura de cada pessoa devem ser informados pelo teclado.

A geração da data de nascimento deve ser feita aleatoriamente através da função abaixo

*/

/*
    O programa deve, na tela de abertura, apresentar opções para:

    inserir uma matricula;
    listar todos as matriculas e respectivas alturas;
    listar as matriculas das pessoas que nasceram antes de uma certa data fornecida.


Cada uma destas opções deve ser implementada em uma função separada.
Para realizar o exercício, utilize como base o programa apresentado abaixo.

*/

typedef struct
{
    long int matricula;
    float altura;
    Data nascimento;
} Pessoa;


void CriaData(Data *D);

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
            AdicionaPessoa(povo, p, qtdPessoas);
        }
        if (opcao == 2)
        {
            ImprimeTodasAsPessoas(povo, qtdPessoas);
        }
        if (opcao == 3)
        {
            LeDataDeTeclado(&dia);
            ImprimeMaisVelhos(povo, qtdPessoas, dia);
        }
    } while (opcao != 4);
}

void CriaData(Data *D)
{
    D->mes = 1 + (rand() % 12);
    D->ano = 1950 + (rand() % 49);
    D->dia = 1 + (rand() % 30);
}
