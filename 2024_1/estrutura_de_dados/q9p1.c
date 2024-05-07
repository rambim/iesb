#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#define TAM 1000


char pilha[TAM];

int topo=0;

char pop();
int push(char x);

int main()
{
    int qtd_testes=0;
    int i,erro=0;
    char letra;

    char * texto;
    

    scanf("%d",&qtd_testes);

    while(qtd_testes--)
    {
        texto = (char*)calloc(TAM,sizeof(char));
        scanf("%s",texto);
        topo=0;
        erro=0;

        for(i=0;i<strlen(texto) && !erro;i++)
        {
            if (texto[i] == '(')
            {
                push(texto[i]);
            }
            else
            {
                if (texto[i] == ')')
                {
                    letra = pop();
                    if (letra != '(')
                    {
                        erro=1;
                    }
                }
            }
        }

        if (topo!=0)
            erro=1;

        if (erro)
            printf("NAO\n");
        else
            printf("SIM\n");
        free(texto);
    }
}

int push(char x)
{
    if (topo==TAM)
    {
        return 0;
    }

    pilha[topo] = x;
    topo++;
    return 1;
}

char pop()
{
    if (topo==0)
    {
        return ' ';
    }
    else
    {
        topo--;
        return pilha[topo];
    }

}

