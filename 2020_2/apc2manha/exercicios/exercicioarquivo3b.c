#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int comeca_com_b(char *linha);
int qtd_b_iniciais_na_linha(char *linha);

int main()
{
    FILE *arq;
    char linha[100];
    int count = 0;

    arq = fopen("nomes.txt", "r");
    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
        return 0;
    }

    while (fgets(linha, 100, arq) != NULL)
    {
        count = count + qtd_b_iniciais_na_linha(linha);
    }
    fclose(arq);

    printf("\nExistem %d nomes com a inicial B", count);
    printf("\n");
    return 0;
}

int qtd_b_iniciais_na_linha(char *linha)
{
    int i;
    int count=0;
    int inicio=1;

    for (i = 0; i < strlen(linha); i++)
    {
        if (inicio)
        {
            if (linha[i] == 'b' || linha[i] == 'B')
            {
                count++;
                inicio=0;
            }
        }
        else
        {
            if (linha[i] == ' ')
            {
                inicio=1;
            }
        }
        
    }
    return count;
}