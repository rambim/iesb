#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct aluno
{
    char nome[30];
    long int matricula;
    int idade;
    float n1,n2,media;
}aluno;

void mostrar_turma(aluno * turma, int qtd_alunos);
void mostrar_turma(aluno * turma, int qtd_alunos);
void preenche_turma(aluno * turma,int qtd_alunos);
void preenche_aluno (aluno * a);
float calcula_media(float n1, float n2);

int main()
{
    int qtd_alunos;
    aluno * turma;
    int turma_preenchida=0;
    int opcao;
    printf("\n Digite a quantidade de alunos: ");
    scanf("%d",&qtd_alunos);
    turma = (aluno*)malloc(sizeof(aluno)*qtd_alunos);

    do
    {
        printf("\n 1 - Preenche turma");
        printf("\n 2 - mostrar turma");
        scanf("%d",&opcao);
        
        switch(opcao)
        {
            case 1:
                preenche_turma(turma,qtd_alunos);
                turma_preenchida=1;
                break;

            case 2:
            if (turma_preenchida)
            {

                mostrar_turma(turma,qtd_alunos);
            }
            else
            {
                printf("\n Preencha a turma antes. ");
            }
        
                break;
            case 5:
                printf("\n Saindo do programa");
                break;
            default:
                printf("\n Opcao invalida");
                break;
        }
    } while (opcao!=5);
    



    return 0;   
}

void preenche_aluno (aluno * a)
{
    printf("\n Digite o nome do aluno: ");
    __fpurge(stdin); // fflush(stdin);
    fgets(a->nome,30,stdin);
    printf("\n Digite sua matricula: ");
    scanf("%ld",&a->matricula);
    printf("\n Digite sua idade: ");
    scanf("%d",&a->idade);
    printf("\n Digite a nota1 :");
    scanf("%f",&a->n1);
    printf("\n Digite a nota2 :");
    scanf("%f",&a->n2);
    a->media=calcula_media(a->n1,a->n2);
}

void preenche_turma(aluno * turma,int qtd_alunos)
{
    int i;
    for(i;i<qtd_alunos;i++)
    {
        preenche_aluno(&turma[i]);

    }
}

float calcula_media(float n1, float n2)
{
    int retorno;
    retorno = (n1+n2)/2.0;
    return retorno;
}

void mostrar_turma(aluno * turma, int qtd_alunos)
{
    int i;
    for(i=0;i<qtd_alunos;i++)
    {
        printf("\n Nome = %s Matricula = %ld Media = %f",turma[i].nome,turma[i].matricula,turma[i].media);
    }
}