/* Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
finalizar o programa, deve-se liberar a área de memória alocada */

#include <stdio.h>
#include <stdlib.h>

void vetor(int *vetor, int n){
  int i = 0;
  printf("Quais valores o vetor terá?\n");
  for(i = 0; i < n; i++){
   scanf("%d", &vetor[i]); 
  }
}

int main(){
  int n, i;

  // Solicita o tamanho do vetor
  printf("Tamanho do vetor que deseja: ");
  scanf("%d", &n);
  while(n <= 0){
    printf("Digite um número inteiro positivo! ");
    scanf("%d", &n);
  }
  // Aloca memória dinamicamente
  int *v = (int *) malloc(n * sizeof(int));
  if(v == NULL){    // Caso tenha algum erro ao alocar a memória
    printf("Erro ao alocar memória.\n");
    return 1;
  }

  vetor(v, n);    // Chama a função passando como parâmetro "*v" e "n"

  // Laço para imprimir os elementos do vetor
  for(i = 0; i < n; i++){
    printf("%d ", v[i]);
  }

  // Liberação de memória
  free(v);
  return 0;
}
