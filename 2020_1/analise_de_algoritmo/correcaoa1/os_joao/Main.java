
public class Main {

	public static void main(String[] args) {
		
		System.out.println("João Pedro Borba Pereira - 1512082081");
		System.out.println("João Victor Batista Vital - 1512082107");
		System.out.println();
		
		int conj[] = {5,4,10,8,9,6};
		int n = conj.length;
		int capacidade = 19;
		
		Recursivo recursivo = new Recursivo();
		Dinamica dinamica = new Dinamica();
		Backtracking backtracking = new Backtracking();
		
		recursivo(conj, n, capacidade);
		dinamica(conj, n, capacidade);
		backtracking.backtracking(conj, n, capacidade);
		

	}

	private static void dinamica(int[] conj, int n, int capacidade) {
		if(Dinamica.isdinamica(conj, n, capacidade)) {
			System.out.println("Existe um subconjunto.");
		}else {
			System.out.println("Não existe um subconjunto");
		}
	}

	private static void recursivo(int[] conj, int n, int capacidade) {
		if(Recursivo.isSubsetSum(conj, n, capacidade)) {
			System.out.println("Existe um subconjunto.");
		}else {
			System.out.println("Não existe um subconjunto");
		}
	}

}
