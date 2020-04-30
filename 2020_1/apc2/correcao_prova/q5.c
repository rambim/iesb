

#include <stdio.h>
#include <stdlib.h>
#define tam 50

typedef struct aluno
{
    int matricula;
    float n1, n2, media;
    int notas_preenchidas;
    int media_calculada;
} aluno;

void reseta_turma(aluno *vet, int qtd);
void mostrar_aluno(aluno a);
void incluir(aluno *turma, int tamanho_turma, int *qtd_alunos);
int buscar(aluno *turma, int qtd_de_alunos, int matricula_procurada);
int incluir_notas(aluno *turma, int qtd_do_alunos, int matricula_procurada);
int calcula_media(aluno *turma, int qtd_de_alunos);
void mostrar_alunos(aluno *turma, int qtd_de_alunos);
void menu(aluno *turma, int *qtd_de_alunos);

int main()
{

    aluno turma[tam];
    int qtd_alunos = 0;

    reseta_turma(turma, tam);
    menu(turma, &qtd_alunos);

    return 0;
}

void menu(aluno *turma, int *qtd_de_alunos)
{
    int opcao;
    int matricula_procurada;
    int retorno;

    do
    {
        printf("\n 1 - Incluir aluno ");
        printf("\n 2 - Buscar aluno");
        printf("\n 3 - Incluir notas");
        printf("\n 4 - Calcular medias");
        printf("\n 5 - Mostrar alunos");
        printf("\n 9 - sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            incluir(turma, tam, qtd_de_alunos);
            break;
        case 2:
            printf("\n Qual matricula deseja buscar? ");
            scanf("%d", &matricula_procurada);
            retorno = buscar(turma, *qtd_de_alunos, matricula_procurada);

            if (retorno == 0)
            {
                printf("\n Aluno nao encontrado ");
            }

            break;
        case 3:
            printf("\n Qual matricula receber as notas? ");
            scanf("%d", &matricula_procurada);
            incluir_notas(turma, *qtd_de_alunos, matricula_procurada);
            break;
        case 4:

            calcula_media(turma, *qtd_de_alunos);
            break;
        case 5:
            mostrar_alunos(turma, *qtd_de_alunos);
            break;
        case 9:
            printf("\n saindo ... \n");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    } while (opcao != 9);
}

void reseta_turma(aluno *vet, int qtd)
{
    int i;

    for (i = 0; i < qtd; i++)
    {
        vet[i].matricula = 0;
        vet[i].n1 = 0;
        vet[i].n2 = 0;
        vet[i].media = 0;
        vet[i].notas_preenchidas = 0;
        vet[i].media_calculada = 0;
    }
    return;
}

void incluir(aluno *turma, int tamanho_turma, int *qtd_alunos)
{
    if (*qtd_alunos >= tamanho_turma)
    {
        printf("\n Turma cheia!");
        return;
    }

    printf("\n Digite a matricula do novo aluno: ");
    scanf("%d", &turma[*qtd_alunos].matricula);

    *qtd_alunos = *qtd_alunos + 1;
    return;
}

// 1 - se encontruo
// 0 - se não encontrou

int buscar(aluno *turma, int qtd_de_alunos, int matricula_procurada)
{
    int i;

    if (qtd_de_alunos == 0)
    {
        printf("\n Turma vazia");
        return 0;
    }

    for (i = 0; i < qtd_de_alunos; i++)
    {
        if (turma[i].matricula == matricula_procurada)
        {
            mostrar_aluno(turma[i]);
            return 1;
        }
    }
    return 0;
}

void mostrar_aluno(aluno a)
{
    printf("\n Matricula: %d", a.matricula);

    if (a.notas_preenchidas)
    {
        printf("\n Nota1 : %f  Nota2 : %f", a.n1, a.n2);
    }

    if (a.media_calculada)
    {
        printf("\n Media: %f", a.media);
    }
}

int incluir_notas(aluno *turma, int qtd_do_alunos, int matricula_procurada)
{
    int i;
    int opcao;
    if (qtd_do_alunos == 0)
    {
        printf("\n turma vazia");
        return 0;
    }

    for (i = 0; i < qtd_do_alunos; i++)
    {
        if (turma[i].matricula == matricula_procurada)
        {
            if (turma[i].notas_preenchidas)
            {

                printf("\n Notas já preenchidas! Deseja atualizar\n 1- Sim 2 - Nao ");
                do
                {
                    scanf("%d", &opcao);
                    if (opcao != 1 && opcao != 2)
                    {
                        printf("\n opcao invalida, digite novamente: ");
                    }

                    switch (opcao)
                    {
                    case 1:
                        printf("\n Digite a n1: ");
                        scanf("%f", &turma[i].n1);
                        printf("\n Digite a n2: ");
                        scanf("%f", &turma[i].n2);
                        printf("\n Notas atualizadas!");
                        turma[i].media = 0;
                        turma[i].media_calculada = 0;

                        break;
                    case 2:
                        printf("\n AS notas nao foram alteradas");
                        break;
                    }
                } while (opcao != 1 && opcao != 2);
            }
            else
            {
                printf("\n Digite a n1: ");
                scanf("%f", &turma[i].n1);
                printf("\n Digite a n2: ");
                scanf("%f", &turma[i].n2);
                printf("\n Notas atualizadas!");
                turma[i].notas_preenchidas = 1;
                turma[i].media = 0;
                turma[i].media_calculada = 0;
            }
            return 1;
        }
    }
    return 0;
}

int calcula_media(aluno *turma, int qtd_de_alunos)
{

    int i;
    if (qtd_de_alunos == 0)
    {
        printf("\n turma vazia");
        return 0;
    }

    for (i = 0; i < qtd_de_alunos; i++)
    {

        if (turma[i].notas_preenchidas && !turma[i].media_calculada)
        {
            turma[i].media = (turma[i].n1 + turma[i].n2) / 2.0;
            turma[i].media_calculada = 1;
        }
    }

    return 1;
}

void mostrar_alunos(aluno *turma, int qtd_de_alunos)
{
    int i;

    if (qtd_de_alunos == 0)
    {
        printf("\n turma vazia");
        return;
    }

    for (i = 0; i < qtd_de_alunos; i++)
    {
        mostrar_aluno(turma[i]);
    }
}