#include <stdio.h> 
#define tamanho 50
  
int SubsetSum(int conjunto[], int tamanhoConjunto, int capacidade){ 

    if (capacidade == 0) {
    	return 1; 
	}
    if (tamanhoConjunto == 0 && capacidade != 0) {
    	return 0; 
	}

    if (conjunto[tamanhoConjunto - 1] > capacidade) {
        return SubsetSum(conjunto, tamanhoConjunto - 1, capacidade); 
    }       
    return SubsetSum(conjunto, tamanhoConjunto - 1, capacidade) || 
           SubsetSum(conjunto, tamanhoConjunto - 1, capacidade - conjunto[tamanhoConjunto - 1]);  
}   

int main() { 

    int conjunto[tamanho]; 
    int capacidade, tamanhoConjunto;
    
    printf("Digite a capacidade e o tamanho do conjunto: \n");
	scanf("%d %d",&capacidade,&tamanhoConjunto);

	printf("Digite os valores: \n");
	for (int i=0;i<tamanhoConjunto;i++){
		  scanf("%d",&conjunto[i]); 
	}
   
    if (SubsetSum(conjunto, tamanhoConjunto, capacidade) == 1) {
    	printf("\nTRUE"); 
	} else{
	    printf("\nFALSE"); 
	}
    return 0; 
} 
