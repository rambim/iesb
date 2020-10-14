#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato
{
    char nome[30];
    int idade;
    int sexo;
    float altura;
}contato;
void mostrar_contato(contato x);

int main()
{
    contato * ptr;

    ptr = malloc(sizeof(contato));
    printf("\n");

    ptr->idade = 30;
    ptr->sexo = 1;
    strcpy(ptr->nome,"Felippe Giuliani");
    mostrar_contato(*ptr);
    mostrar_contato2(ptr);
    return 0;
}

void mostrar_contato(contato x)
{
    printf("\n Nome do contato = %s",x.nome);
    printf("\n idade do contato = %d",x.idade);
    printf("\n sexo do contato = %d",x.sexo);
    printf("\n altura do contato = %f",x.altura);
}

void mostrar_contato2(contato * x)
{
    printf("\n Nome do contato = %s",(*x).nome);
    printf("\n Nome do contato = %s",x->nome);
    printf("\n idade do contato = %d",(*x).idade);
    printf("\n sexo do contato = %d",(*x).sexo);
    printf("\n altura do contato = %f",(*x).altura);

}