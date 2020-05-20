
public class Main {

	public static void main(String[] args) {
	       int set[] = {2,4,7,9};
	       int size = 11;
	    
	       SubSet ss = new SubSet(set, size);
	       ss.solve(0,0);
		    
	       if(ss.hasSolution == false)
		  System.out.print("Nao ha combinacao");
	    }
}
