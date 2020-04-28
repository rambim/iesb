#include<stdlib.h>
#include<stdio.h>

#include<math.h>
#include<locale.h>
#include<string.h>



int remover(int * vetor, int x){
	int i, a=0, r;
	int num = x/2;
	int vetor2[num];
	
	for(i=0;i<x;i++){
		printf("%d, ", vetor[i]);
		i++;
		if(i<x){
			vetor2[a]=vetor[i];
			a++;
		}
	}
	
	printf("Lista 2: ");
	for(i=0;i<num;i++){
		printf("%d ", vetor2[i]);
	}
	printf("\n");
	
	if(a==1){
		printf("\nCarta Remaneceste: %d", vetor2[0]);
		r = vetor2[0];
		return r;
	}else{
		remover(vetor2,num);
	}
	
	
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int num, i, resultado;
	
	printf("Digite o n�mero de cartas\n");
	scanf("%d", &num);
	
	int vetor[num];
	
	for(i=0;i<num;i++){
		vetor[i]=i+1;
	}
	
	printf("Cartas Discartadas: ");
	resultado = remover(vetor, num);
	printf("\nCarta Remaneceste: %d", resultado);
	
}
