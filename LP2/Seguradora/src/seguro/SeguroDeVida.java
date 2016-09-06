package seguro;

public class SeguroDeVida extends Seguro{
	
	private int idadeSegurado;
	
	public SeguroDeVida(String nomeBeneficiario, float valorApolice, int idadeSegurado) {
		super(nomeBeneficiario, valorApolice);
		this.idadeSegurado = idadeSegurado;
	}
	
	@Override
	float valorPremio() {
		if(getIdadeSegurado() < 50) return (float) (getValorApolice() * (getValorApolice() * 0.10));
		return getValorApolice();
	}

	public int getIdadeSegurado() {
		return idadeSegurado;
	}

	public void setIdadeSegurado(int idadeSegurado) {
		this.idadeSegurado = idadeSegurado;
	}
}
