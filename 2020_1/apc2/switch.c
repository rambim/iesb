#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tipo_de_usuario;

    // 1 - Cliente
    // 2 - Administrador
    // 3 - Cliente de baixa renda

    printf("\n Digite o tipo do usuario");
    scanf("%d", &tipo_de_usuario);

    switch (tipo_de_usuario)
    {
    case 1:
        printf("\n Ir para funcoes de cliente");
        break;
    case 2:
        printf("\n Funcoes de administrador");
        break;
    case 3:
        printf("\n Funcoes de cliente de baixa renda");
        break;
    default:
        printf("\n Tipo de usuario nao previsto");

        break;
    }

    printf("\n");
    return 0;
}