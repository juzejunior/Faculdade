package seguro;

public abstract class Seguro {

	protected String nomeBeneficiario;
	protected float valorApolice;
	
	public Seguro(String nomeBeneficiario, float valorApolice) {
		this.nomeBeneficiario = nomeBeneficiario;
		this.valorApolice = valorApolice;
	}

	abstract float valorPremio();
	
	public String getNomeBeneficiario() {
		return nomeBeneficiario;
	}

	public void setNomeBeneficiario(String nomeBeneficiario) {
		this.nomeBeneficiario = nomeBeneficiario;
	}
	
	public float getValorApolice() {
		return valorApolice;
	}

	public void setValorApolice(float valorApolice) {
		this.valorApolice = valorApolice;
	}

	@Override
	public String toString() {
		return "Seguro [nomeBeneficiario=" + nomeBeneficiario + ", valorApolice=" + valorApolice + "]";
	}
}
