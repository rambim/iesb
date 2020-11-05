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
int EscolheOpcao();
void CriaData(Data *D);
void LePessoaDeTeclado(Pessoa *p);
void AdicionaPessoa(Pessoa *povo, Pessoa p, int qtd);
void ImprimeTodasAsPessoas(Pessoa *x, int qtd);
void ImprimeMaisVelhos(Pessoa *x, int qtd, Data data_limite);
void mostrar(Pessoa x);
void LeDataDeTeclado(Data *data_limite);

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
            if (qtdPessoas != 0)
                LeDataDeTeclado(&dia);

            ImprimeMaisVelhos(povo, qtdPessoas, dia);
        }
    } while (opcao != 4);

    printf("\n");
    return 0;
}

void ImprimeTelaDeOpcoes()
{
    printf("\n 1 - Incluir Matricula");
    printf("\n 2 - Listas Matriculas");
    printf("\n 3 - Listar Matriculas por Data");
}

int EscolheOpcao()
{

    int retorno;
    printf("\nopcao: ");
    scanf("%d", &retorno);
    return retorno;
}

void LePessoaDeTeclado(Pessoa *p)
{
    printf("\n Digite a matricula: ");
    scanf("%ld", &p->matricula);
    printf("\n Digite a altura: ");
    scanf("%f", &p->altura);
    CriaData(&p->nascimento);
}

void CriaData(Data *D)
{
    D->mes = 1 + (rand() % 12);
    D->ano = 1950 + (rand() % 49);
    D->dia = 1 + (rand() % 30);
}

void AdicionaPessoa(Pessoa *povo, Pessoa p, int qtd)
{
    if (qtd == 10)
    {
        printf("\n Povo cheio!");
    }
    else
    {
        povo[qtd] = p;
    }
}

void ImprimeTodasAsPessoas(Pessoa *x, int qtd)
{
    int i;
    if (qtd == 0)
    {
        printf("\n Lista vazia");
    }
    else
    {
        for (i = 0; i < qtd; i++)
        {
            mostrar(x[i]);
        }
    }
}

void LeDataDeTeclado(Data *data_limite)
{
    printf("\n Digite a data limite no formato DD/MM/AAAA: ");
    scanf("%d/%d/%d", &data_limite->dia, &data_limite->mes, &data_limite->ano);
}

void ImprimeMaisVelhos(Pessoa *x, int qtd, Data data_limite)
{
    int i;

    if (qtd == 0)
    {
        printf("\n Lista vazia");
    }
    else
    {
        for (i = 0; i < qtd; i++)
        {
            if (x[i].nascimento.ano < data_limite.ano)
            {
                mostrar(x[i]);
            }
            else
            {
                if (x[i].nascimento.ano == data_limite.ano)
                {
                    if (x[i].nascimento.mes < data_limite.mes)
                    {
                        mostrar(x[i]);
                    }
                    else
                    {
                        if (x[i].nascimento.mes == data_limite.mes)
                        {
                            if (x[i].nascimento.dia < data_limite.dia)
                            {
                                mostrar(x[i]);
                            }
                        }
                    }
                }
            }
        }
    }
}

void mostrar(Pessoa x)
{
    printf("\nMatricula %ld Altura %f Nascimento: %d/%d/%d", x.matricula, x.altura, x.nascimento.dia, x.nascimento.mes, x.nascimento.ano);
}