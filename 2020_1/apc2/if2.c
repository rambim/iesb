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

    if (tipo_de_usuario  == 1)
    {
        printf("\n Ir para funcoes de cliente");
    }
    
    else
    {

        printf("\n ir para funcoes de administrador");
    }

    printf("\n Progama errado!!!!");
    

    printf("\n");
    return 0;
}