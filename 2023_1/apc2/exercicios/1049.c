#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

int main()
{
    char nomes[10][50];

    int i;
    int j;

    for (i = 0; i < 3; i++)
    {

        fgets(nomes[i], 49, stdin);
        nomes[i][strlen(nomes[i]) - 1] = '\0';
    }



    if (strcmp(nomes[0],"vertebrado")==0)
    {
        if (strcmp(nomes[1], "ave")==0)
        {
            if (strcmp(nomes[2], "carnivoro")==0)
            {
                printf("aguia");
            }
            else
            {
                if (strcmp(nomes[2], "onivoro")==0)
                {
                    printf("pomba");
                }
            }
        }
        else
        {
            if (strcmp(nomes[1], "mamifero")==0)
            {
                if (strcmp(nomes[2], "onivoro")==0)
                {
                    printf("homem");
                }
                else
                {
                    if (strcmp(nomes[2], "herbivoro")==0)
                    {
                        printf("vaca");
                    }
                }
            }
        }
    }
    else
    {
        if (strcmp(nomes[0], "invertebrado")==0)
        {
            if (strcmp(nomes[1], "inseto")==0)
            {
                if (strcmp(nomes[2], "hematofago")==0)
                {
                    printf("pulga");
                }
                else
                {
                    if (strcmp(nomes[2], "herbivoro")==0)
                    {
                        printf("lagarta");
                    }
                }
            }
            else
            {
                if (strcmp(nomes[1], "anelideo")==0)
                {
                    if (strcmp(nomes[2], "hematofago")==0)
                    {
                        printf("sanguessuga");
                    }
                    else
                    {
                        if (strcmp(nomes[2], "onivoro")==0)
                        {
                            printf("minhoca");
                        }
                    }
                }
            }
        }
    }

    printf("\n");
    return 0;
}