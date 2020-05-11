
public class Recursivo {
	
	public Recursivo() {
		
	}
	
	static boolean isSubsetSum(int conj[], int n, int capacidade) { 
		
		if (capacidade == 0) {
            return true; 
		}
        if (n == 0 && capacidade != 0) {
            return false; 
        }
 
		if (conj[n-1] > capacidade) {
		return isSubsetSum(conj, n-1, capacidade);
		}
		
		return isSubsetSum(conj, n-1, capacidade) ||  
		isSubsetSum(conj, n-1, capacidade-conj[n-1]); 
		} 

}
