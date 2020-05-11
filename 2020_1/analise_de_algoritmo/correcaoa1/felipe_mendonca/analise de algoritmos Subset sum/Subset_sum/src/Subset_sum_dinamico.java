
public class Subset_sum_dinamico {
	
	private String[] vet_valores = new String[0];
	private boolean existe_o_somatorio = false;
	private float[] vetfloat = new float[0];
	private boolean[][] matriz;
	private float somatorio;
	
	Subset_sum_dinamico (float[] vetfloat,float somatorio) {
		this.setVetfloat(vetfloat);
		this.setSomatorio(somatorio);
		this.setMatriz(new boolean[this.getVetfloat().length][Math.round(this.getSomatorio())+1]);
		this.gerar_matriz_de_valores_possiveis();
		this.setExiste_o_somatorio(this.getMatriz()[this.getMatriz().length-1][this.getMatriz()[0].length-1]);
		this.obter_somatorios_possiveis();
	}
	
	public void gerar_matriz_de_valores_possiveis() {
		for(int i=0;i<this.getMatriz().length;i++) {
			for(int j=0;j<this.getMatriz()[0].length;j++) {
				if(i==0) {
					if(j==0 || j== this.getVetfloat()[0]) {
						this.getMatriz()[i][j]=true;
					}
					else {
						this.getMatriz()[i][j]=false;
					}
				}
				else {
					if(j<this.getVetfloat()[i]) {
						this.getMatriz()[i][j]=this.getMatriz()[i-1][j];
					}
					else if(this.getMatriz()[i-1][j]) {
						this.getMatriz()[i][j]=true;
					}
					else if(this.getMatriz()[i-1][j-(int)this.getVetfloat()[i]]) {
						this.getMatriz()[i][j]=true;
					}
					else {
						this.getMatriz()[i][j]=false;
					}
				}
			}
		}
	}
	
	public void obter_somatorios_possiveis() {
		if(this.isExiste_o_somatorio()) {
			this.obter_somatorios_possiveis_recursivo(this.getMatriz().length-1,this.getMatriz()[0].length-1,"");
		}
	}
	
	public void obter_somatorios_possiveis_recursivo(int valor_linha,int valor_coluna,String valores) {
		if((valor_linha==0 || valor_coluna ==0)) {
			if(valor_coluna == 0) {
				this.add_vet_valores(valores);
			}
			else {
				this.add_vet_valores(valores+this.getVetfloat()[valor_linha]);
			}
			return;
		}
		else {
			if(this.getMatriz()[valor_linha-1][valor_coluna]) {
				this.obter_somatorios_possiveis_recursivo(valor_linha-1, valor_coluna, valores);
			}
			if((int)this.getVetfloat()[valor_linha]<=valor_coluna && this.getMatriz()[valor_linha][valor_coluna-(int)this.getVetfloat()[valor_linha]]) {
				this.obter_somatorios_possiveis_recursivo(valor_linha-1,valor_coluna-(int)this.getVetfloat()[valor_linha], valores+this.getVetfloat()[valor_linha]+" ");
			}
		}
	}

	public void existe_somatorio_mais_numeros() {
		if(this.isExiste_o_somatorio()) {
			System.out.println("\nExiste o somatorio desejado!!!");
			this.show_valores_somatorio();
		}
		else {
			System.out.println("\nNão existe o somatorio desejado");
		}
	}
	
	public void mostrar_matriz() {
		for(int i=0; i<this.getMatriz().length; i++) {
			System.out.print("\n"+this.getVetfloat()[i]+":");
			for(int j=0; j<this.getMatriz()[0].length;j++) {
				System.out.print(this.getMatriz()[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	private void add_vet_valores(String valores) {
		String[] vet_valores_aux = new String[this.getVet_valores().length+1];
		for(int i=0;i<this.getVet_valores().length;i++) {
			vet_valores_aux[i] = this.getVet_valores()[i];
		}
		vet_valores_aux[this.getVet_valores().length] = valores;
		this.setVet_valores(vet_valores_aux);
	}
	
	private void show_valores_somatorio() {
		for(int i=0;i<this.getVet_valores().length;i++) {
			System.out.println(this.getVet_valores()[i]);
		}
	}
	
	public String[] getVet_valores() {
		return vet_valores;
	}

	public void setVet_valores(String[] vet_valores) {
		this.vet_valores = vet_valores;
	}

	public boolean isExiste_o_somatorio() {
		return existe_o_somatorio;
	}

	public void setExiste_o_somatorio(boolean existe_o_somatorio) {
		this.existe_o_somatorio = existe_o_somatorio;
	}

	public float[] getVetfloat() {
		return vetfloat;
	}

	public void setVetfloat(float[] vetfloat) {
		this.vetfloat = vetfloat;
	}

	public boolean[][] getMatriz() {
		return matriz;
	}

	public void setMatriz(boolean[][] matriz) {
		this.matriz = matriz;
	}

	public float getSomatorio() {
		return somatorio;
	}

	public void setSomatorio(float somatorio) {
		this.somatorio = somatorio;
	}
	
}
