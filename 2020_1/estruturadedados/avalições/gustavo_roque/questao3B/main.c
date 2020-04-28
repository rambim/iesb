#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int push1(char txt, char*x);

int pop1(char *x, int final1);

void xCy(char*x);

int main()
{
    int  opc = 0,i;
    char * pilha;

    pilha = (char*)malloc(sizeof(char)*100);
    do{
        printf("1 -- xCy. \n");

        printf("9 -- exit. \n \n");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            for(i = 0; i< 100; i++)
                pilha[i] = NULL;
            xCy(pilha);
           break;
        default:
            break;
        }
    }while(opc != 9);
    return 0;
}

int push1(char txt,char*x)
{
    int i;
    for (i = 0; i<100; i++)
    {
        if(x[i] == NULL)
        {
            x[i] = txt;
            return i;
        }
    }
}


int pop1(char *x, int final1)
{
    x[final1] = NULL;

    return (final1-1);
}

void xCy(char * x)
{
    char *txt;
    int final1, i;
    txt = (char*)malloc(sizeof(char)*100);

    printf("Insira a palavra: \n");
    fflush(stdin);
    fgets(txt, 100, stdin);

    txt[strlen(txt) -1] = '\0';

    for (i = 0; i<strlen(txt); i++)
    {
        final1 = push1(txt[i], x);
        final1 = push1('D', x);
    }
    final1 = pop1(x, final1);

    printf("%s String invertida e com D inserido entre as letras. \n\n", x);

}
