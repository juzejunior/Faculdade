package seguro;

public class SeguroAutomovel extends Seguro{

	private int numChassi, anoFabricacao;
	
	public SeguroAutomovel(String nomeBeneficiario, float valorApolice, int numChassi, int anoFabricacao) {
		super(nomeBeneficiario, valorApolice);
		// TODO Auto-generated constructor stub
		this.numChassi = numChassi;
		this.anoFabricacao = anoFabricacao;
	}

	@Override
	float valorPremio() {
		
		return (float) ((float) (getValorApolice() * 0.90) - ((getValorApolice() * 0.02)* getAnoFabricacao()));
	}

	public int getNumChassi() {
		return numChassi;
	}

	public void setNumChassi(int numChassi) {
		this.numChassi = numChassi;
	}

	public int getAnoFabricacao() {
		return anoFabricacao;
	}

	public void setAnoFabricacao(int anoFabricacao) {
		this.anoFabricacao = anoFabricacao;
	}

	@Override
	public String toString() {
		return "SeguroAutomovel [numChassi=" + numChassi + ", anoFabricacao=" + anoFabricacao + "]";
	}
	
}
