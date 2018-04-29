public class Item {
	private String descricao;
	private int quantidade;
	private double valorUnitario;

	public int getQuantidade() {
		return quantidade;
	}

	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}

	public double getValorUnitario() {
		return valorUnitario;
	}

	public void setValorUnitario(double valorUnitario) {
		this.valorUnitario = valorUnitario;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public double getTotalItem(){
		return (this.quantidade * this.valorUnitario);
	}
	public String toString(){
		return this.descricao+ " Qtd:"+this.quantidade+ "  Valor Unitário:"+this.valorUnitario;
	}


	public void update(double indice) {
		
		this.valorUnitario = this.valorUnitario*indice;
		
	}
}
