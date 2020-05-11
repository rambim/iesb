#include <stdio.h>
#include <stdlib.h>
#define tamanho 50

int conjunto[tamanho], auxiliar[tamanho];
int capacidade,tamanhoConjunto;

void mostrarSubSet(){
		
	if (auxiliar[capacidade]==(-1)){                                                                            // 1
		printf("Nao possui subsets\n");																			

	} else{
  		printf("\n--> [ ");
  		while (capacidade>0){																					// n + 1
    		printf(" %d ",conjunto[auxiliar[capacidade]]);
   			capacidade-=conjunto[auxiliar[capacidade]];  														// + n
  		}																										// ==> 1 + n + 1 + n => 2n + 2 => n
  		printf(" ]");
	}	
}

void subSet(){
	int i,j,k;	
	
	for (i=0;i<=capacidade;i++){										//2(n + 1) => 2n+2       
  		auxiliar[i]=(-1);  												// +n  
	}
	
	auxiliar[0]=0;														// +1   
	
	for (i=0;i<capacidade;i++){											//2(n+1)
		if (auxiliar[i]!=(-1)){											// n
			for (j=auxiliar[i]+1;j<=tamanhoConjunto;j++) {				//n(t+1) * 2
      			k=i+conjunto[j];     									// n * t
		  	
      			if (auxiliar[k]==(-1) || auxiliar[k]>j){				// 2*(N * t)
       				auxiliar[k]=j;										// n* t  
      			}
    		}															//  ====> 2n + 2 + n + 1 + 2n + 2 + n + 2nt + 2n + nt + 2nt + nt
		}
	}
	
	mostrarSubSet();
}                                     



main(){

	printf("Digite a capacidade e o tamanho do conjunto: \n");
	scanf("%d %d",&capacidade,&tamanhoConjunto);     // 1

	printf("Digite os valores: \n",tamanhoConjunto); 

	for (int i=1;i<=tamanhoConjunto;i++){  // 2(t+1)
  		scanf("%d",&conjunto[i]);  //t
	}							// ===> 1 + 2t + 2 + t ========> 3t +3
  	subSet();
}
