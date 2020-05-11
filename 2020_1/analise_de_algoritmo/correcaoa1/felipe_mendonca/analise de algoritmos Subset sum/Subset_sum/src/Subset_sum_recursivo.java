
public class Subset_sum_recursivo {
	
	public String[] vet_valores = new String[0];
	public float[] vetfloat = new float[0];
	public float somatorio;
	
	Subset_sum_recursivo (float[] vetfloat,float somatorio) {
		this.setVetfloat(vetfloat);
		this.setSomatorio(somatorio);
	}
	
	public boolean existe_o_somatorio_recursivo(float somatorio,int interação,String valores) {
		if(somatorio == 0) {
			add_vet_valores(valores);
			return true;
		}
		else if(interação == this.getVetfloat().length) {
			return false;
		}
		else {
			boolean ignora = existe_o_somatorio_recursivo(somatorio,interação+1,valores);
			boolean considera = existe_o_somatorio_recursivo(somatorio-this.getVetfloat()[interação],interação+1,valores+this.getVetfloat()[interação]+" ");
			return ignora || considera;
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
	
	public void existe_somatorio_mais_numeros() {
		if(this.existe_o_somatorio_recursivo(this.getSomatorio(), 0,"")) {
			System.out.println("\nExiste o somatorio desejado!!!");
			this.show_valores_somatorio();
		}
		else {
			System.out.println("\nNão existe o somatorio desejado");
		}
	}

	public String[] getVet_valores() {
		return vet_valores;
	}

	public void setVet_valores(String[] vet_valores) {
		this.vet_valores = vet_valores;
	}

	public float[] getVetfloat() {
		return vetfloat;
	}

	public void setVetfloat(float[] vetfloat) {
		this.vetfloat = vetfloat;
	}

	public float getSomatorio() {
		return somatorio;
	}

	public void setSomatorio(float somatorio) {
		this.somatorio = somatorio;
	}
	
	
}
