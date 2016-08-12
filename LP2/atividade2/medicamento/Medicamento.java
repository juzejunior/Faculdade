package medicamento;

public class Medicamento {

	private String nome;
	private float preco;
	private String princAtivo;
	private Data validade;
	private Data fabricacao;
	private String fornecedor;
	
	public Medicamento(String nome, float preco, String princAtivo, Data fabricacao, Data validade) 
	{
		this.nome = nome;
		this.preco = preco;
		this.princAtivo = princAtivo;
		this.fabricacao = fabricacao;
		this.validade = validade;
	}

	public Medicamento(String nome, String fabricante, float preco, String princAtivo, Data fabricacao)
	{
		this.nome = nome;
		this.preco = preco;
		this.princAtivo = princAtivo;
		this.fabricacao = fabricacao;
		this.fornecedor = fabricante;
		Data validade = fabricacao;
		validade.setAno(validade.getAno()+1);
	}
	
	public float getPreco()
	{
		return this.preco;
	}
	
	public boolean podeSubstituir(Medicamento gen)
	{
		if(gen.princAtivo.equals(this.princAtivo)) return true;
		return false;
	}
	
	
}
