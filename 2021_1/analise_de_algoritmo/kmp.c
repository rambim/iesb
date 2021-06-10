#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *lps(char *padrao, int tam);
int kmp(char *texto, char *padrao, int *lps_table);
int busca_string(char *texto, char *padrao);
int compara_texto(char *texto1, int tam_1, char *texto2, int tam_2);
void delay();

int main()
{
    clock_t t1, t2; // duas variáveis para guardar o registro clock
    // char *texto = "ATGCAGCGCGTGAACATGATCATGGCAGAATCACCAGGCCTCATCACCATCTGCCTTTTAGGATATCTACTCAGTGCTGAATGTACAGTTTTTCTTGATCATGAAAACGCCAACAAAATTCTGAATCGGCCAAAGAGGTATAATTCAGGTAAATTGGAAGAGTTTGTTCAAGGGAACCTTGAGAGA GAATGTATGGAAGAAAAGTGTAGTTTTGAAGAAGCACGAGAAGTTTTTGAAAACACTGATGGAAGCAGTATGTTGATGGAGATCATGGAAGCAGTATAAGAACAACTGAATTTTGGAAGCAGTATGTTGATGGAGATCAGTGTGAGTCCAATCCATGTTTAAATGGCGGCAGTTGCAAGGATGATGCAGCGCGTGAACATGATCATGGCAGAATCACCAGGCCTCATCACCATCTGCCTTTTAGGATATCTACTCAGTGCTGAATGTACAGTTTTTCTTGATCATGAAAACGCCAACAAAATTCTGAATCGGCCAAAGAGGTATAATTCAGGTAAATTGGAAGAGTTTGTTCAAGGGAACCTTGAGAGA GAATGTATGGAAGAAAAGTGTAGTTTTGAAGAAGCACGAGAAGTTTTTGAAAACACTGATGGAAGCAGTATGTTGATGGAGATCATGGAAGCAGTATAAGAACAACTGAATTTTGGAAGCAGTATGTTGATGGAGATCAGTGTGAGTCCAATCCATGTTTAAATGGCGGCAGTTGCAAGGATGATGCAGCGCGTGAACATGATCATGGCAGAATCACCAGGCCTCATCACCATCTGCCTTTTAGGATATCTACTCAGTGCTGAATGTACAGTTTTTCTTGATCATGAAAACGCCAACAAAATTCTGAATCGGCCAAAGAGGTATAATTCAGGTAAATTGGAAGAGTTTGTTCAAGGGAACCTTGAGAGA GAATGTATGGAAGAAAAGTGTAGTTTTGAAGAAGCACGAGAAGTTTTTGAAAACACTGATGGAAGCAGTATGTTGATGGAGATCATGGAAGCAGTATAAGAACAACTGAATTTTGGAAGCAGTATGTTGATGGAGATCAGTGTGAGTCCAATCCATGTTTAAATGGCGGCAGTTGCAAGGATGATGCAGCGCGTGAACATGATCATGGCAGAATCACCAGGCCTCATCACCATCTGCCTTTTAGGATATCTACTCAGTGCTGAATGTACAGTTTTTCTTGATCATGAAAACGCCAACAAAATTCTGAATCGGCCAAAGAGGTATAATTCAGGTAAATTGGAAGAGTTTGTTCAAGGGAACCTTGAGAGA GAATGTATGGAAGAAAAGTGTAGTTTTGAAGAAGCACGAGAAGTTTTTGAAAACACTGATGGAAGCAGTATGTTGATGGAGATCATGGAAGCAGTATAAGAACAACTGAATTTTGGAAGCAGTATGTTGATGGAGATCAGTGTGAGTCCAATCCATGTTTAAATGGCGGCAGTTGCAAGGATGATGCAGCGCGTGAACATGATCATGGCAGAATCACCAGGCCTCATCACCATCTGCCTTTTAGGATATCTACTCAGTGCTGAATGTACAGTTTTTCTTGATCATGAAAACGCCAACAAAATTCTGAATCGGCCAAAGAGGTATAATTCAGGTAAATTGGAAGAGTTTGTTCAAGGGAACCTTGAGAGA GAATGTATGGAAGAAAAGTGTAGTTTTGAAGAAGCACGAGAAGTTTTTGAAAACACTGATGGAAGCAGTATGTTGATGGAGATCATGGAAGCAGTATAAGAACAACTGAATTTTGGAAGCAGTATGTTGATGGAGATCAGTGTGAGTCCAATCCATGTTTAAATGGCGGCAGTTGCAAGGATGATGCAGCGCGTGAACATGATCATGGCAGAATCACCAGGCCTCATCACCATCTGCCTTTTAGGATATCTACTCAGTGCTGAATGTACAGTTTTTCTTGATCATGAAAACGCCAACAAAATTCTGAATCGGCCAAAGAGGTATAATTCAGGTAAATTGGAAGAGTTTGTTCAAGGGAACCTTGAGAGA GAATGTATGGAAGAAAAGTGTAGTTTTGAAGAAGCACGAGAAGTTTTTGAAAACACTGATGGAAGCAGTATGTTGATGGAGATCATGGAAGCAGTATAAGAACAACTGAATTTTGGAAGCAGTATGTTGATGGAGATCAGTGTGAGTCCAATCCATGTTTAAATGGCGGCAGTTGCAAGGATG";
    // char *padrao = "ATCCATGTTTAAATGGCGGCAGTTGCAAGGATGCAGTATAAGAACAACTGAATTTTGGAAGCAGTATGTTGATGGAGATCAGTGTGAGTCCAATCCATGTTTAAATGGCGGCAGTTGCAAGGATG";
    char *texto = "Felippe Giuliani Lourenco Rodrigues";
    char *padrao = "Giuliani";
    int retorno;
    float diff;

    int *lps_table;

    t1 = clock(); // pega esse instante
    lps_table = lps(padrao, strlen(padrao));
    retorno = kmp(texto, padrao, lps_table);
    t2 = clock(); // pega esse instante

    diff = (((float)t2 - (float)t1) / 1000000.0F); // mile segundos
    printf("\nTempo KMP: %f", diff);

    t1 = clock(); // pega esse instante
    retorno = busca_string(texto, padrao);
    t2 = clock();                                  // pega esse instante
    diff = (((float)t2 - (float)t1) / 1000000.0F); // mile segundos
    printf("\nTempo NAIVE: %f", diff);

    if (retorno == -1)
        printf("\nNao existe %s em %s", padrao, texto);
    else
        printf("\n Existe '%s' na posicao %d de '%s'", padrao, retorno, texto);

    printf("\n");
    return 0;
}

int *lps(char *padrao, int tam)
{
    int *lps_table;
    lps_table = (int *)calloc(tam, sizeof(int));

    int i, j;

    i = 0;
    j = 1;

    while (j < tam)
    {
        if (padrao[i] == padrao[j])
        {
            lps_table[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = lps_table[i - 1];
            }
            else
            {
                lps_table[j] = 0;
                j++;
            }
        }
    }
    return lps_table;
}

int kmp(char *texto, char *padrao, int *lps_table)
{
    int i, j = 0;

    for (i = 0; i < strlen(texto); i++)
    {
        delay();
        if (texto[i] == padrao[j])
        {
            j++;
            if (j == strlen(padrao))
                return i - (j - 1);
        }
        else
        {
            if (j != 0)
                j = lps_table[j - 1];
        }
    }
    return -1;
}

int busca_string(char *texto, char *padrao)
{
    int i;
    int tamanho_texto = strlen(texto);
    int tamanho_padrao = strlen(padrao);
    int flag = 0;
    for (i = 0; i < strlen(texto) - (strlen(padrao) - 1) && !flag; i++)
    {
        if (compara_texto(&texto[i], tamanho_padrao, padrao, tamanho_padrao))
        {
            flag = 1;
        }
    }

    if (flag)
        return i - 1;
    else
        return -1;
}

int compara_texto(char *texto1, int tam_1, char *texto2, int tam_2)
{
    int i;
    if (tam_1 != tam_2)
        return 0;

    for (i = 0; i < tam_1; i++)
    {
        delay();
        if (texto1[i] != texto2[i])
            return 0;
    }
    return 1;
}

void delay()
{
    long long int i, j, z;
    for (i = 0; i < 100000; i++)
        for (j = 0; j < 10000; j++)
            z = 1;
}