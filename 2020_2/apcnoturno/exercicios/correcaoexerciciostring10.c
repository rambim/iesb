#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>

int main()
{

    char s[100];
    char resultado[100];
    int i, codigo;

    printf("\n Digite uma string: ");
    __fpurge(stdin);
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = '\0';

    for (i = 0; i < strlen(s); i++)
    {
        codigo = tolower(s[i]);
        printf("\nASC = %d", codigo);

        codigo = codigo + 3;
        if (codigo>122)
        {
            codigo = codigo - 26;
        }

        resultado[i] = codigo;
    }
    resultado[i] = '\0';

    printf("\nString......: %s", s);
    printf("\nCodificada..: %s", resultado);

    printf("\n");
    return 0;
}