

// Leia 3 valores, no caso, variáveis A, B e C, que são as três notas de um aluno. A seguir, calcule a média do aluno, sabendo que a nota A tem peso 2, a nota B tem peso 3 e a nota C tem peso 5. Considere que cada nota pode ir de 0 até 10.0, sempre com uma casa decimal.
// Entrada

// O arquivo de entrada contém 3 valores com uma casa decimal, de dupla precisão (double).
// Saída

// Imprima a mensagem "MEDIA" e a média do aluno conforme exemplo abaixo, com 1 dígito após o ponto decimal e com um espaço em branco antes e depois da igualdade. Assim como todos os problemas, não esqueça de imprimir o fim de linha após o resultado, caso contrário, você receberá "Presentation Error".


#include <stdio.h>
#include <stdlib.h>

int main()
{
    double valores[3];
    double media;

    
    scanf("%lf",&valores[0]);
    scanf("%lf",&valores[1]);
    scanf("%lf",&valores[2]);

    // printf("\n 1 valor lido : %lf",valores[0]);
    // printf("\n 2 valor lido : %lf",valores[1]);
    // printf("\n 3 valor lido : %lf",valores[2]);

    media = ((valores[0] * 2) + (valores[1] * 3) + (valores[2]*5))/ (double)10; 

    printf("MEDIA = %.1lf",media);


    printf("\n");
    return 0;
}