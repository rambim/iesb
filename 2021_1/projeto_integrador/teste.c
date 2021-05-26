#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trata_linha ( char * linha, int tam);

int main()
{
    char texto[10] = "áa";
    int i;

    printf("1 - %d 2 - %d",texto[0],texto[1]);

    if (texto[0]==-61)
    {
        texto[0] = 'a';
        texto[1] = texto[2];
        texto[2] = texto[3];
    }

    // for(i=0;i<strlen(texto);i++)
    // {
    //     printf("\nC: %c",texto[i]);
    // }
    
    printf("%s",texto);
    return 0;
}
