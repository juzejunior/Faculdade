package seguro;

public class SeguroResidencial extends Seguro {

	private String enderecoImovel;
	private int anoConstrucao;
	
	/*Reutilizando o construtor de Seguro*/
	public SeguroResidencial(String nomeBeneficiario, float valorApolice, String enderecoImovel, int anoConstrucao) {
		super(nomeBeneficiario, valorApolice);
		this.enderecoImovel = enderecoImovel;
		this.anoConstrucao = anoConstrucao;
	}
	
	/*Aplicando polimorfismo*/
	@Override
	float valorPremio() {
		return (float) (getValorApolice() - ((getValorApolice()*0.2)/100) * getAnoConstrucao());
	}

	public String getEnderecoImovel() {
		return enderecoImovel;
	}

	public void setEnderecoImovel(String enderecoImovel) {
		this.enderecoImovel = enderecoImovel;
	}

	public int getAnoConstrucao() {
		return anoConstrucao;
	}

	public void setAnoConstrucao(int anoConstrucao) {
		this.anoConstrucao = anoConstrucao;
	}
}
