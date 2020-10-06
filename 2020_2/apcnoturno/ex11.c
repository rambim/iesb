#include <stdio.h>
#include <stdlib.h>


typedef struct aluno
{
    float n1;
    float n2;
    float media;
    long int matricula;

}aluno;

void mostrar_dados_aluno(aluno x);

int main()
{

    aluno felippe;

    printf("\n Digite a n1 do Felippe: ");
    scanf("%f",&felippe.n1);
    printf("\n Digite a n2 do Felippe: ");
    scanf("%f",&felippe.n2);

    felippe.media = (felippe.n1 + felippe.n2) / 2.0;

    printf("\n Digite a matricula do Felippe: ");
    scanf("%ld",&felippe.matricula);

    mostrar_dados_aluno(felippe);

    printf("\n");
    return 0;
}


void mostrar_dados_aluno(aluno x)
{
    printf("\n Matricula = %ld N1 = %f N2 = %f Media = %f",x.matricula,x.n1,x.n2,x.media);
}