import java.util.Scanner;

public class Main {

	public static Scanner input = new Scanner(System.in);
	public static float[] vetfloat = new float[0];
	public static float somatorio;
	

	public static void main(String[] args) {
		menu();
	}
	
	public static void menu() {
		while(true) {
			try {
				System.out.println("\nEscolha uma op��o:"
						+"\n1-Subset sum recursivo"
						+"\n2-Subset sum dinamico"
						+"\n3-Subset sum arvore"
						+"\n0-sair");
				switch(Integer.parseInt(input.nextLine())) {
				    case 1:
				    	obtem_vetor_de_numeros_e_somatorio();
				    	subset_sum_recursivo();
					break;
				    case 2:
				    	obtem_vetor_de_numeros_e_somatorio();
				    	subset_sum_dinamico();
				    break;
				    case 3:
				    	obtem_vetor_de_numeros_e_somatorio();
				    	subset_sum_arvore();
				    break;
			        case 0:
			        	try {
					        System.out.println("\nDeseja sair:"
					        		 +"\n1-Sim"
								     +"\n2-Não");
					        switch(Integer.parseInt(input.nextLine())) {
					                case 1:
					            	return;
					            	case 2:
					            	break;
					            	default:
					            		throw new IllegalArgumentException ();
					            	}
			        	}
						catch(IllegalArgumentException e) {
							System.out.println("\nOpção invalida\n\n");
						}
				   break;
				   default:
					   throw new IllegalArgumentException ();
				}
			}
			catch(IllegalArgumentException e) {
				System.out.println("\nOpção invalida\n\n");
			}
		}
	}
	
	public static void obtem_vetor_de_numeros_e_somatorio() {
		System.out.println("\nDigite os valores:");
		obtem_vetor_float(input.nextLine());
		System.out.println("\nDigite o somatorio desejado:");
		somatorio = Integer.parseInt(input.nextLine());
	}
	
	private static void obtem_vetor_float(String string) {
		String[] vetor_string = string.split( "[, ?.@]+");
		float[] vetor_float = new float[vetor_string.length];
		for(int i=0;i<vetor_string.length;i++) {
			vetor_float[i]=Float.parseFloat(vetor_string[i]);
			}
		vetfloat = vetor_float;
		}

	private static void subset_sum_recursivo() {
		Subset_sum_recursivo subset_sum_recursivo = new Subset_sum_recursivo(vetfloat,somatorio);
		subset_sum_recursivo.existe_somatorio_mais_numeros();
	}
	
	private static void subset_sum_dinamico() {
		Subset_sum_dinamico subset_sum_dinamico = new Subset_sum_dinamico(vetfloat,somatorio);
		subset_sum_dinamico.existe_somatorio_mais_numeros();
	}
	
	private static void subset_sum_arvore() {
		Subset_sum_arvore subset_sum_arvore = new Subset_sum_arvore(vetfloat,somatorio);
		subset_sum_arvore.existe_somatorio_mais_numeros();
	}


}
