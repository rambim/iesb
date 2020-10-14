#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int dia, mes, ano;
} Data;

typedef struct Pessoa
{
    long int matricula;
    float altura;
    Data nascimento;
} Pessoa;

void ImprimeTelaDeOpcoes();
void CriaData(Data *D);
void AdicionaPessoa(Pessoa *povo, Pessoa p, int qtdPessoas);
int EscolheOpcao();
void LePessoaDeTeclado(Pessoa *x);
void ImprimeTodasAsPessoas(Pessoa *povo, int qtdPessoas);
void LeDataDeTeclado(Data *dia);
void ImprimeMaisVelhos(Pessoa *povo, int qtdPessoas, Data dia);

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
            qtdPessoas++;
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
        if (opcao == 4)
        {
            printf("\n Saindo do programa");
        }
    } while (opcao != 4);
}

void ImprimeTelaDeOpcoes()
{
    printf("\n 1 - inserir um nome");
    printf("\n 2 - listar todos os nomes e respectivas alturas");
    printf("\n 3 - listar os nomes das pessoas que nasceram antes de uma certa data fornecida.");
    printf("\n 4 - Sair");
}

int EscolheOpcao()
{
    int x;
    printf("\n Digite a opcao: ");
    scanf("%d", &x);
    return x;
}

void LePessoaDeTeclado(Pessoa *x)
{
    printf("\n Digite a matricula da pessoa: ");
    scanf("%ld", &x->matricula);
    printf("\n Digite a altura da pessoa:");
    scanf("%f", &x->altura);
    CriaData(&x->nascimento);
}

void CriaData(Data *D)
{
    D->mes = 1 + (rand() % 12);
    D->ano = 1950 + (rand() % 49);
    D->dia = 1 + (rand() % 30);
}

void AdicionaPessoa(Pessoa *povo, Pessoa p, int qtdPessoas)
{
    if (qtdPessoas >= 10)
    {
        printf("\n Capacidade maxima atingida");
    }
    else
    {
        povo[qtdPessoas] = p;
    }

    /*
    povo[qtdPessoas].matricula  = p.matricula;
    povo[qtdPessoas].altura     = p.altura;
    povo[qtdPessoas].nascimento = p.nascimento;  
*/
}

void ImprimeTodasAsPessoas(Pessoa *povo, int qtdPessoas)
{
    int i;

    if (qtdPessoas == 0)
    {
        printf("\n Não existem pessoas");
    }
    else
    {
        for (i = 0; i < qtdPessoas; i++)
        {
            printf("\n Matricula      : %ld", povo[i].matricula);
            printf("\n Altura         : %f", povo[i].altura);
            printf("\n Data Nascimento: %d/%d/%d", povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
        }
    }
}

void LeDataDeTeclado(Data *dia)
{
    printf("\n Digite a data limite: (Formato DD/MM/AAAA): ");
    scanf("%d/%d/%d", &dia->dia, &dia->mes, &dia->ano);
    /*
    printf("\n digite o dia da data limite: ");
    scanf("%d",&dia->dia);
    printf("\n Digite o mes da data limite");
    scanf("%d",&dia->mes);
    printf("\n Digite a ano da data limite");
    scanf("%d",&dia->ano);
*/
}

void ImprimeMaisVelhos(Pessoa *povo, int qtdPessoas, Data dia)
{
    int i;
    printf("\n Data limite: %d/%d/%d", dia.dia, dia.mes, dia.ano);
    int tem_pelo_menos_1_velho = 0;

    for (i = 0; i < qtdPessoas; i++)
    {
        if ((povo[i].nascimento.ano < dia.ano) ||
            (povo[i].nascimento.ano == dia.ano && povo[i].nascimento.mes < dia.mes) ||
            (povo[i].nascimento.ano == dia.ano && povo[i].nascimento.mes == dia.mes && povo[i].nascimento.dia < dia.dia))
        {
            printf("\n Matricula      : %ld", povo[i].matricula);
            printf("\n Altura         : %f", povo[i].altura);
            printf("\n Data Nascimento: %d/%d/%d", povo[i].nascimento.dia, povo[i].nascimento.mes, povo[i].nascimento.ano);
            tem_pelo_menos_1_velho = 1;
        }
    }

    if (tem_pelo_menos_1_velho == 0)
    {
        printf("\n Não tem ninguem mais velho do que a data");
    }

    /*        
    for (i = 0; i < qtdPessoas; i++)
    {
        if (povo[i].nascimento.ano < dia.ano)
        {
            printf("");
        }
        else
        {
            if (povo[i].nascimento.ano == dia.ano)
            {
                if (povo[i].nascimento.mes < dia.mes)
                {
                    printf("");
                }
                else
                {
                    if (povo[i].nascimento.mes == dia.mes)
                    {
                        if (povo[i].nascimento.dia < dia.dia)
                        {
                            printf("");
                        }
                    }
                }
            }
        }
    }
*/
}