
public class Arvore_nó {
	
	private float  valor_restante;
	private float  valor_somado;
	
	Arvore_nó (float  valor_restante,float  valor_somado){
		this.setValor_restante(valor_restante);
		this.setValor_somado(valor_somado);
	}

	public float getValor_restante() {
		return valor_restante;
	}
	public void setValor_restante(float valor_restante) {
		this.valor_restante = valor_restante;
	}
	public float getValor_somado() {
		return valor_somado;
	}
	public void setValor_somado(float valor_somado) {
		this.valor_somado = valor_somado;
	}
}
