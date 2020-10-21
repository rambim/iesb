#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{

    int i;
    char nome[300];
    int tamanho;
    

    printf("Digite seu nome: ");
    // scanf("%s",nome);
    // gets(nome);
    fgets(nome,30,stdin);

    // for(i=0;i<30;i++)
    // {
    //     if (nome[i] == '\n')
    //     {
    //         nome[i] = '\0';
    //     }
    // }


    //strlen = string lenght
    
    nome[strlen(nome)-1] = '\0';



    printf("\nNome lido: %s",nome);
    printf("\nTamanho: %d",tamanho);





    return 0;
}