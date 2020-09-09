#include <stdio.h>
#include <stdlib.h>



typedef struct aluno
{
    long int matricula;
    float n1;
    float n2;
    float media;

}aluno;

void mostrar_dados_aluno(aluno x);
float calcula_media_2(aluno x);

int main()
{
    aluno vet[3];

    int i;

    for(i=0;i<3;i++)
    {
        printf("\n Digite a Matricula do %d aluno: ",i+1);
        scanf("%ld",&vet[i].matricula);
        printf("\n Digite a n1 do %d aluno :",i+1);
        scanf("%f",&vet[i].n1);
        printf("\n Digite a n2 do %d aluno :",i+1);
        scanf("%f",&vet[i].n2);

        vet[i].media = calcula_media(vet[i].n1, vet[i].n2);

        vet[i].media = calcula_media_2(vet[i]);
        calcula_media_3(&vet[i]);
    }

    for(i=0;i<3;i++)
    {
        mostrar_dados_aluno(vet[i]);
    }


}
void calcula_media_3(aluno  * x)
{
    (*x).media = ((*x).n1 + (*x).n2) / 2.0;
}

void mostrar_dados_aluno(aluno x)
{
    printf("\n Matricula = %ld N1 = %f N2 = %f Media = %f",x.matricula,x.n1,x.n2,x.media);
}

float calcula_media(float n1, float n2)
{
    return (n1+n2)/2.0;
}

float calcula_media_2(aluno x)
{
    return (x.n1 + x.n2) / 2.0;
}



// totalizadores de portarias

// por tipo
// por estado
// habilitação positivo
// desabilitação negativo
// por mês.