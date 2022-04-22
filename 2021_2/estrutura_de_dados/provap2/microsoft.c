// Escreva um programa que liste todas as diferentes palavras que existem em um texto.
// Neste caso, uma palavra é definida como uma sequência de letras, maiúsculas ou minúsculas.
// Palavras com apenas uma letra também deverão ser consideradas. Seu programa deverá ser case
// insensitive. Por exemplo, palavras como "Microsoft", "microsoft" ou "MICROSOFT" deverão ser
// consideradas como a mesma palavra. A entrada contém no máximo 10000 linhas de texto, cada uma
// delas com no máximo 200 caracteres. O fim de entrada é determinado pelo EOF. Na saída do programa
// você deve imprimir uma lista das diferentes palavras que aparecem no texto, uma palavra por linha.
// Todas as palavras devem ser impressas com letras minúsculas, em ordem alfabética. Deverá haver no máximo 5000 palavras distintas.
// Funções que podem auxiliar: "int toupper(int c)"  e "int tolower(int c)". https://www.tutorialspoint.com/c_standard_library/c_function_toupper.htm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char lista_de_palavras[5000][200];
int qtd_palavras=0;

int letra_valida(char letra);
void converte_para_minusculo(char *texto);
void tratar_linha(char *linha);
void incluir_palavra_lista(char * palavra);
void mostrar_lista_de_palavras();
void ordenar_lista_de_palavras();
int main()
{

    char linha[200];

    FILE *arq;

    arq = fopen("texto.txt", "r");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {
        while (fgets(linha, 200, arq) != 0)
        {
            // printf("\n Linha: %s", linha);
            tratar_linha(linha);
        }
        fclose(arq);
    }

    printf("\n Mostrando antes de ordenar: ");
    mostrar_lista_de_palavras();
    ordenar_lista_de_palavras();

    printf("\n Mostrando depois de ordenar: ");
    mostrar_lista_de_palavras();

    printf("\n");
    return 0;
}

void tratar_linha(char *linha)
{
    char palavra[200];
    int i, j = 0;
    
    for (i = 0; i < strlen(linha); i++)
    {
        if (letra_valida(linha[i]))
        {
            palavra[j] = linha[i];
            j++;
        }
        else
        {
            palavra[j] = '\0';
            if (j>=1)
            {
                converte_para_minusculo(palavra);
                // printf("\n Palavra: %s", palavra);
                incluir_palavra_lista(palavra);

            }
            j = 0;
        }
    }
}

int letra_valida(char letra)
{
    if (letra >= 97 && letra <= 122)
        return 1;
    if (letra >= 65 && letra <= 90)
        return 1;
    return 0;
}

void converte_para_minusculo(char *texto)
{
    int i;

    for (i = 0; i < strlen(texto); i++)
    {
        texto[i] = tolower(texto[i]);
    }
}


void incluir_palavra_lista(char * palavra)
{
    int i;

    for(i=0;i<qtd_palavras;i++)
    {
        if (strcmp(palavra,lista_de_palavras[i])==0)
        {
            printf("\n Palavra ja existe na lista de palavras");
            return;
        }
    }

    strcpy(lista_de_palavras[qtd_palavras],palavra);
    qtd_palavras++;
    
}

void mostrar_lista_de_palavras()
{
    int i;

    for(i=0;i<qtd_palavras;i++)
    {
        printf("\n Palavra %d : %s",i+1,lista_de_palavras[i]);
    }
}


void ordenar_lista_de_palavras()
{
    long int pass,i;
    int trocou=1;
    char aux[500];

    for(pass=0;pass<qtd_palavras-1 && trocou==1;pass++)
    {
        trocou=0;
        for(i=0;i<qtd_palavras-1-pass;i++)
        {
            if (strcmp(lista_de_palavras[i],lista_de_palavras[i+1])> 0)
            {
                strcpy(aux,lista_de_palavras[i]);
                strcpy(lista_de_palavras[i],lista_de_palavras[i+1]);
                strcpy(lista_de_palavras[i+1],aux);
                trocou=1;
            }
        }
    }
}


void bubblesort(long int * vet, long int tam)
{
    long int pass,i,aux;
    int trocou=1;

    for(pass=0;pass<tam-1 && trocou==1;pass++)
    {
        trocou=0;
        for(i=0;i<tam-1-pass;i++)
        {
            if (vet[i] > vet[i+1])
            {
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                trocou=1;
            }
        }
    }
}