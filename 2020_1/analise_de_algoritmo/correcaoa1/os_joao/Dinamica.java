import java.util.ArrayList;

public class Dinamica {
	
	static boolean dinamica[][];
	static int aux;
	static ArrayList<Integer> conjunto;
	static int soma = 0;
	
	public Dinamica() {
		
	}
	
	static boolean isdinamica(int conj[], int n, int capacidade) {
		
		//Ordena o conjunto
		int[] conjOrdenado = ordenaVetor(conj);
		
		
		dinamica = new boolean[100][capacidade+1];
		
		//Cria a matriz dinamica colocando True em todo j = 0
		for(int i = 0; i < conjOrdenado.length; i++) {                      //(n+1)*2
			for(int j=0; j<=capacidade; j++) {                              //n*(n+1)*2
				if(j == 0) {												//n*n
					dinamica[conjOrdenado[i]][j] = true;					//n*n
				}else {
					dinamica[conjOrdenado[i]][j] = false;
				}
			}
		}
		
		
		//Monta a matriz dinamica
		
		
		for(int i=0; i<conjOrdenado.length; i++) {																	//(n+1)*2
			for(int j=0; j<=capacidade; j++) {																		//n*(n+1)*2
				//Monta a primeira linha
				if(i == 0) {																						//n*n
					if(conjOrdenado[i] == j) {																		//n*n
						dinamica[conjOrdenado[i]][j] = true;														//n*n
					}
				//Montando as demais linhas
				}else {
					//Copiando todos os valores da linha de cima até o
					//valor do conjunto ser igual ou maior que a da capacidade
					if(j<conjOrdenado[i]) {																			//n*n
						dinamica[conjOrdenado[i]][j] = dinamica[conjOrdenado[i-1]][j];								//n*n
					}else {
						//verifica a linha acima, em caso de verdadeiro, só copia para a linha de baixo. 
						//Em caso de falso, subtrai o valor do conteudo do conjunto (conjOrdenado[i]) da linha j, 
						//e copia o valor do conteudo para a posição.
						if(!dinamica[conjOrdenado[i-1]][j]) {														//n*n
							if(dinamica[conjOrdenado[i-1]][j-conjOrdenado[i]]) {									//n*n
								dinamica[conjOrdenado[i]][j] = true;												//n*n
							}else {
								dinamica[conjOrdenado[i]][j] = false;
							}
						}else {
							dinamica[conjOrdenado[i]][j] = true;
						}
					}
				}
				aux = j;
			}
		}
		
		//Imprime matriz dinamica
		
		for(int i=0; i<conjOrdenado.length; i++) {														//(n+1)*2
					
			System.out.print(conjOrdenado[i] + " - ");
					
			for(int j=0; j<=capacidade; j++) {															//n*(n+1)*2
						
				if(dinamica[conjOrdenado[i]][j]) {														//n*n
					System.out.print("True  |");
				}else {
					System.out.print("False |");
				}
			}
			System.out.println("");
		}
		
		//Acha um subconjunto
		
		conjunto = new ArrayList<Integer>();
		
		//Verifica se o ultimo termo da raiz é verdadeiro.
		if(dinamica[conjOrdenado[conjOrdenado.length-1]][aux]) {												//1
			
			for(int i=conjOrdenado.length; i>=0; i--) {															//(n+1)*2
				if(i==0) {																						//n
					if(dinamica[conjOrdenado[i]][aux]) {														//n
						for(int j=0; j<conjunto.size(); j++) {													//n*(n+1)*2
							soma += conjunto.get(j);
						}
						if(soma == capacidade) {																//n*n
							
						}else {
							System.out.println(soma);
							conjunto.add(conjOrdenado[i]);
						}
					}
				}else {
					if(!dinamica[conjOrdenado[i-1]][aux]) {
						conjunto.add(conjOrdenado[i]);
						aux -= conjOrdenado[i];
					}
				}
			}
		}
		
		//Imprime subconjunto
		
		System.out.print("Um subconjunto é: ");
		for(int i=0; i<conjunto.size(); i++) {													//(n+1)*2								
			System.out.print(conjunto.get(i)+ " ");
		}
		System.out.println();
				
		
		//Existe algum subconjunto?
		
		return dinamica[conjOrdenado[conjOrdenado.length-1]][aux];								//1
		
		
		
		
		//return true;
		
		
		
	}
	
	static int[] ordenaVetor(int vetor[]) {
		
		
		int aux = 0;
		 
        for (int i = 0; i < vetor.length; i++){
        	for (int j = 0; j < vetor.length; j++){
        		if (vetor[i] < vetor[j]){
	                        aux = vetor[i];
	                        vetor[i] = vetor[j];
	                        vetor[j] = aux;
	                    }
	                }
	            }
        
		return vetor;
	}
	
	

}
