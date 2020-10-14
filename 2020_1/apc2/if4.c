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

    if (tipo_de_usuario == 1)
    {
        printf("\n Ir para funcoes de cliente");
    }
    else
    {
        if (tipo_de_usuario == 2)
        {
            printf("\n Funcoes de administrador");
        }
        else
        {
            if (tipo_de_usuario == 3)
            {
                printf("\n Funcoes de cliente de baixa renda");
            }
            else
            {
                printf("\n Tipo de usuario nao previsto");
            }
            
        }

    }
    

    printf("\n");
    return 0;
}