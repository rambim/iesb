#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int dia, mes, ano;
} Data;

typedef struct
{
    long int matricula;
    float altura;
    Data nascimento;
} Pessoa;

void ImprimeTelaDeOpcoes();
int EscolheOpcao();
void LePessoaDeTeclado(Pessoa *p);
void CriaData(Data *D);
void AdicionaPessoa(Pessoa *povo, Pessoa p, int qtdPessoas);
void ImprimeTodasAsPessoas(Pessoa *povo, int qtdPessoas);
void LeDataDeTeclado(Data *d);
void ImprimeMaisVelhos(Pessoa *galera, int qtd, Data d);

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
            if (qtdPessoas == 10)
            {
                printf("\n Vetor de pessoas cheio");
            }
            else
            {
                AdicionaPessoa(povo, p, qtdPessoas);
                qtdPessoas++;
            }
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

void ImprimeTelaDeOpcoes()
{
    printf("\n 1 - Inserir matricula ");
    printf("\n 2 - Listas todas Matriculas");
    printf("\n 3 - Listar matriculas antereriores a uma data");
    printf("\n 4 - Sair do programa");
}

int EscolheOpcao()
{
    int opcao;
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void LePessoaDeTeclado(Pessoa *p)
{
    printf("\n Digite a matricula da pessoa: ");
    scanf("%ld", &p->matricula);
    printf("\n Digite a altura da pessoa: ");
    scanf("%f", &p->altura);
    CriaData(&p->nascimento);
}
void CriaData(Data *D)
{
    D->mes = 1 + (rand() % 12);
    D->ano = 1950 + (rand() % 49);
    D->dia = 1 + (rand() % 30);
}

void AdicionaPessoa(Pessoa *povo, Pessoa p, int qtdPessoas)
{
    povo[qtdPessoas] = p;
}

void ImprimeTodasAsPessoas(Pessoa *povo, int qtdPessoas)
{
    int i;
    if (qtdPessoas == 0)
    {
        printf("\n Lista vazia");
    }
    else
    {
        for (i = 0; i < qtdPessoas; i++)
        {
            printf("\nMatricula: %ld Altura: %f Nascimento %d/%d/%d", povo[i].matricula, povo[i].altura, povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
        }
    }
}

void LeDataDeTeclado(Data *d)
{
    printf("\n Digite a data limite no formato DD/MM/AAAA: ");
    scanf("%d/%d/%d", &d->dia, &d->mes, &d->ano);
}

void ImprimeMaisVelhos(Pessoa *galera, int qtd, Data d)
{
    int i;
    if (qtd == 0)
    {
        printf("\n Nao existem pessoas na lista");
    }
    else
    {
        for (i = 0; i < qtd; i++)
        {
            if (galera[i].nascimento.ano < d.ano)
            {
                printf("\nMatricula: %ld Altura: %f Nascimento %d/%d/%d", galera[i].matricula, galera[i].altura, galera[i].nascimento.dia, galera[i].nascimento.mes, galera[i].nascimento.ano);
            }
            else
            {
                if (galera[i].nascimento.ano == d.ano)
                {
                    if (galera[i].nascimento.mes < d.mes)
                    {
                        printf("\nMatricula: %ld Altura: %f Nascimento %d/%d/%d", galera[i].matricula, galera[i].altura, galera[i].nascimento.dia, galera[i].nascimento.mes, galera[i].nascimento.ano);
                    }
                    else
                    {
                        if (galera[i].nascimento.mes == d.mes)
                        {
                            if (galera[i].nascimento.dia < d.dia)
                            {
                                printf("\nMatricula: %ld Altura: %f Nascimento %d/%d/%d", galera[i].matricula, galera[i].altura, galera[i].nascimento.dia, galera[i].nascimento.mes, galera[i].nascimento.ano);
                            }
                        }
                    }
                }
            }
        }
    }
}