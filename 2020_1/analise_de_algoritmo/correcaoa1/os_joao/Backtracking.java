
public class Backtracking {
	
	boolean booleano[];
	
	
	public void backtracking(int[] conj, int n, int capacidade) {
		
		int[] conjOrdenado = Dinamica.ordenaVetor(conj);									
		
		
		booleano = new boolean[100];												//1
		int aux;																	//1
		
		int maximo = ((int) Math.pow(2, n+1))/2;									//1
		int base = n+1;																//1
		
		int somatorio = 0;															//1
		
		//Inicia todos os booleanos
		for(int i=0; i<booleano.length; i++) {										//(n+1)*2
			booleano[i] = false;													//n
		}
		
		
		//Verifica todos os subconjuntos
		for(int i=1; i<=maximo; i++) {												//(n+1)*2
			
			somatorio = 0;															//n
			aux = 0;																//n
			//Funciona de forma binaria
			if(booleano[conjOrdenado[0]]) {											//n
				booleano[conjOrdenado[0]] = false;
			}else {
				booleano[conjOrdenado[0]] = true;
			}
			
			for(int j = 1; j <= base; j++) {										//n*(n+1)*2
				
				aux = (int) Math.pow(2, j);											//n*n
				
				if(j >= conjOrdenado.length) {										//n*n
					
				}else {
				
					if(i%aux==0) {													//n*n
						
						if(booleano[conjOrdenado[j]]) {								//n*n
							booleano[conjOrdenado[j]] = false;
						}else {
							booleano[conjOrdenado[j]] = true;
						}
						
					}
				}
			}
			
			
			//Realiza a soma de todos conjuntos marcados como verdadeiro
			for(int j=0; j<booleano.length; j++) {								//n*(n+1)*2
				if(booleano[j]) {												//n*n
					somatorio += j;												//n*n
					
				}
			}
			
			//Se a soma for igual a capacidade, então ele  coloca todos os 
			//conjuntos marcados como verdadeiro dentro de um subconjunto
			if(capacidade == somatorio) {										//n
				System.out.print("Subconjunto: ");
				for(int j=0; j<booleano.length; j++) {							//n*(n+1)*2
					if(booleano[j]) {											//n*n
						System.out.print(" "+j+" ");
					}
				}
				System.out.println();
			}
			
		}
		
	}

}