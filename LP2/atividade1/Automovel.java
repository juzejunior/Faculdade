
public class Automovel {

	private String placa;
	private String modelo;
	private String cor;
	private int ano;
	private String categoria;
	
	public Automovel(String placa, String modelo, String cor, int ano, String categoria) 
	{
		this.placa = placa;
		this.modelo = modelo;
		this.cor = cor;
		this.ano = ano;
		this.categoria = categoria;
	}
	
	public  Automovel(String placa, String modelo, String cor, int ano)
	{
		this(placa, modelo, cor, ano, "básico");
	}

	public String getPlaca() {
		return placa;
	}

	public void setPlaca(String placa) {
		this.placa = placa;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public String getCor() {
		return cor;
	}

	public void setCor(String cor) {
		this.cor = cor;
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}

	public String getCategoria() {
		return categoria;
	}

	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}
	
	public float valorAlocacao(int quantDias)
	{
		if(this.getCategoria().equals("básico")) return quantDias * 120;
		else if(this.getCategoria().equals("luxo")) return quantDias * 160;
		else if(this.getCategoria().equals("superluxo")) return quantDias * 210;
		else return 0;
	}
}
