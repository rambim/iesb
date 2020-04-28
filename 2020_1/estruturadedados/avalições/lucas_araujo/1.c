#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAMANHO_MAXIMO 100

char expressao_matematica[TAMANHO_MAXIMO];
int comeco = 0, topo = 0;

int empty()
{
    return (comeco == topo);
}
int full()
{
    return (topo == TAMANHO_MAXIMO);
}

int push(char c)
{
    if(!full())
    {
        expressao_matematica[topo++] = c;
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    if(!empty()){
        expressao_matematica[topo--];
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int count;


    scanf("%s", expressao_matematica);

    for(count = 0; count < strlen(expressao_matematica); count++){
        if(expressao_matematica[count] == '(')
        {
            push('(');
        }
        else
        {
            if(expressao_matematica[count] == ')')
            {
                if (!pop())
                {
                    printf("Esta incorreto\n");
                    return 0;
                } 
            }
        }
    }

    if(empty())
    {
        printf("Esta correto\n");
    }else
    {
        printf("Esta incorreto\n");
    }
    return 0;
}
