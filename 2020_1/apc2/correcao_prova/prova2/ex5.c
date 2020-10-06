/* Faça um programa que leia u mvetor de dados de 5 livros: título ( máximo 30 letras), 
autor ( máximo 15 letras) e ano. Procure um livro por título, perguntando ao usuário 
qual título deseja buscar. Mostre os dados de todos os livros encontrados.

*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro
{
    char titulo[30];
    char autor[15];
    int ano;

} livro;

void preenche_livro(livro *l);
void mostra_livro ( livro l);
int busca_livro(livro * livros,char * titulo_procurado);

int main()
{
    int i,retorno;
    livro livros[5];
    char titulo_buscado[30];

    for (i = 0; i < 5; i++)
    {
        preenche_livro(&livros[i]);
    }

    printf("\n Digite qual titulo deseja buscar: ");
    __fpurge(stdin);
    fgets(titulo_buscado, 30, stdin);
    titulo_buscado[strlen(titulo_buscado) - 1] = '\0';

    retorno = busca_livro(livros,titulo_buscado);

    if (retorno == -1)
    {
        printf("\n Titulo nao encontrado");
    }
    else
    {
        mostra_livro(livros[retorno]);
    }
    

    return 0;
}

void preenche_livro(livro *l)
{
    printf("\nDigite o titulo do livro: ");
    __fpurge(stdin);
    fgets(l->titulo, 30, stdin);
    l->titulo[strlen(l->titulo) - 1] = '\0';

    printf("\nDigite o autor do livro: ");
    __fpurge(stdin);
    fgets(l->autor, 30, stdin);
    l->autor[strlen(l->autor) - 1] = '\0';

    printf("\nDigite o ano do livro: ");
    scanf("%d", &l->ano);
}

void mostra_livro ( livro l)
{
    printf("\n Titulo: %s Autor: %s Ano: %d",l.titulo,l.autor,l.ano);
}


//  -1 se nao encontrou o livro
//  0 ... 4 a posicao do livro no vetor
int busca_livro(livro * livros,char * titulo_procurado)
{
    int i;

    for(i=0;i<5;i++)
    {
        if (strcmp(livros[i].titulo,titulo_procurado)==0)
        {
            return i;
        }
    }

    return -1;
}