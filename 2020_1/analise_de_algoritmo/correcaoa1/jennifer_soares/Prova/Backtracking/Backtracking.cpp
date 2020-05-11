#include<stdio.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0
#define tamanho 50

int conjunto[tamanho];
int capacidade;
int auxiliar[tamanho];
int possui = FALSE;

int validando(int indiceConjunto,int somaCorrente,int total) {
	return( ((somaCorrente+total)>=capacidade) && ((somaCorrente==capacidade)||(somaCorrente+conjunto[indiceConjunto+1]<=capacidade)));
}

void sumset(int indiceConjunto,int somaCorrente,int total) {
	int j;
	if(validando(indiceConjunto,somaCorrente,total) == 1) {
		if(somaCorrente==capacidade) {
			possui = TRUE;
			printf("\n--> [ ");
			for (j=0;j<=indiceConjunto;j++){
				if(auxiliar[j]){
					printf("%d ",conjunto[j]);
				}
			}
			    
			printf(" ]\n");
		} else {
			auxiliar[indiceConjunto+1]=TRUE;
			sumset(indiceConjunto+1,somaCorrente+conjunto[indiceConjunto+1],total-conjunto[indiceConjunto+1]);
			auxiliar[indiceConjunto+1]=FALSE;
			sumset(indiceConjunto+1,somaCorrente,total-conjunto[indiceConjunto+1]);
		}
	}	
}

void bubbleSort(int tamanhoConjunto){
	int aux;
	
	for (int i=0;i<=tamanhoConjunto;i++){
		for (int j=0;j<tamanhoConjunto-1;j++){
			if(conjunto[j]>conjunto[j+1]) {
				aux = conjunto[j];
				conjunto[j]= conjunto[j+1];
				conjunto[j+1] = aux;
			}
		}  	  
	}
}

int main() {
	int total=0, tamanhoConjunto = 0;

	printf("Digite a capacidade e o tamanho do conjunto:\n");
	scanf("%d %d", &capacidade, &tamanhoConjunto);
	
	printf("Digite os valores:\n");
	for (int i=0;i<tamanhoConjunto;i++) {
		scanf("%d", &conjunto[i]);
		total+=conjunto[i];
	}
	
	bubbleSort(tamanhoConjunto);
	
	if(total<capacidade){
		printf("\nNao possui subsets"); 
	} else{		
		sumset(-1,0,total);

		if(!possui){
			printf("\nNao possui subsets\n");
		}		
	}
}

