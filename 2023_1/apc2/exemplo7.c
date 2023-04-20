#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct t_aluno
{
    char nome[50];
    char matricula[50];
    float nota;
    char genero;
}t_aluno;

void ler_string(char * string, int tam);
void mencao(float x);

int main()
{

    int x;
    t_aluno joaozinho;
    t_aluno ana = { .nome = "Ana", .matricula = "A1", .nota = 7.5, .genero = 'F' };
    t_aluno * ptr;

    ptr = &joaozinho;

    printf("\n Digite o nome do aluno:");
    ler_string(joaozinho.nome,49);

    printf("\n Digite a matricula: ");
    ler_string(joaozinho.matricula,49);

    printf("\n Digite a nota do aluno:");
    scanf("%f",&joaozinho.nota);

    printf("\n Digite o genero: (F ou M)");
    scanf("%c",&joaozinho.genero);

    (*ptr).nota = 10;
    ptr->nota = 10;

    mencao(ana.nota);

    mencao(joaozinho.nota);

    mencao(ptr->nota);


    return 0;
}

void ler_string(char * string, int tam)
{
    fgets(string,tam,stdin);
    string[strlen(string)-1 ]= '\0';
}

void mencao(float x)
{
    if (x>=9)
    {
        printf("\nSS");
    }
    else
    {
        if (x>=7)
        {
            printf("\n MS");
        }
        else
        {
            if (x>=5)
            {
                printf("\n MM");
            }
            else
            {
                printf("\n MI");
            }
        }
    }
}