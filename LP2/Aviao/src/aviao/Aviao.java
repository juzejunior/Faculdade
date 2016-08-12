package aviao;

public class Aviao {
	private String prefixo, modelo, fabricante;
	private int quantAssentos, assentosOcup;
	
	public Aviao(String prefixo, String modelo, String fabricante, int quantAssentos, int assentosOcup) {
		this.prefixo = prefixo;
		this.modelo = modelo;
		this.fabricante = fabricante;
		this.quantAssentos = quantAssentos;
		this.assentosOcup = assentosOcup;
	}

	public String getPrefixo() {
		return prefixo;
	}

	public void setPrefixo(String prefixo) {
		this.prefixo = prefixo;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public String getFabricante() {
		return fabricante;
	}

	public void setFabricante(String fabricante) {
		this.fabricante = fabricante;
	}

	public int getQuantAssentos() {
		return quantAssentos;
	}
	
	public void setQuantAssentos(int quantAssentos) {
		this.quantAssentos = quantAssentos;
	}

	public int getAssentosOcup() {
		return assentosOcup;
	}

	public void setAssentosOcup(int assentosOcup) {
		this.assentosOcup = assentosOcup;
	}

	public int alugarAssento()
	{
		if(this.getAssentosOcup() < this.getQuantAssentos())
		{
			this.setAssentosOcup(this.getAssentosOcup()+1);
			return 0;
		}
		return 1;
	}

	public int getAssentosDisp()
	{
		return this.getQuantAssentos() - this.getAssentosOcup();
	}
}
