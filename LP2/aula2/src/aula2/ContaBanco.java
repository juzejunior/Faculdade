package aula2;

public class ContaBanco {

	private int numero, agencia, limite;
	private double saldo;
	private boolean especial;
	
        public ContaBanco(int numero, int agencia){
            this.numero = numero;
            this.agencia = agencia;
            limite = 0;
            especial = false;
            saldo = 0;
        }
        
        public ContaBanco(int numero, int agencia, int limite){
            this.numero = numero;
            this.agencia = agencia;
            this.limite = limite;
            especial = true;
            saldo = 0;
        }
	/*gets & sets*/
	public int getNumero() {
		return numero;
	}
	public void setNumero(int numero) {
		this.numero = numero;
	}
	public int getAgencia() {
		return agencia;
	}
	public void setAgencia(int agencia) {
		this.agencia = agencia;
	}
	public int getLimite() {
		return limite;
	}
	public void setLimite(int limite) {
		this.limite = limite;
	}
	public double getSaldo() {
		return saldo;
	}
	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}
	public boolean isEspecial() {
		return especial;
	}
	public void setEspecial(boolean especial) {
		this.especial = especial;
	}
	
	public void depositar(float quantidade){
		this.saldo += quantidade;
	}
	
	public float sacar(float quantidade){
		
		if(quantidade <= this.getSaldo()){
			this.saldo -= quantidade;
			return quantidade;
		}else if(this.isEspecial() && this.getLimite() > 0 && quantidade <= this.getLimite()){
			this.saldo -= quantidade;
		}
		
		return 0;
	}
	
	public void consultarSaldo(){

            System.out.printf("Seu saldo é: %.4f\n", this.getSaldo());
	}
}
