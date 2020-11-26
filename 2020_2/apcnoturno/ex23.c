#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *arq;
    char letra;

    arq = fopen("alunosdesesperados.txt", "r");

    if (arq == NULL)
    {
        printf("\n Problemas na abertura do arquivo");
    }
    else
    {

            letra = fgetc(arq);
            while (letra != EOF)
            {
                printf("%c", letra);
                letra = fgetc(arq);
            }
            fclose(arq);
    }

    return 0;
}

// fgets,  fgetc , fscanf, fread
// fputs, fputc, fprintf, fwrite