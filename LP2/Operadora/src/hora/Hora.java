package hora;

public class Hora {

	private int hora, minuto, segundo;

	
	
	public Hora(int hora, int minuto, int segundo) {
		this.hora = hora;
		this.minuto = minuto;
		this.segundo = segundo;
	}

	public int getHora() {
		return hora;
	}

	public void setHora(int hora) {
		this.hora = hora;
	}

	public int getMinuto() {
		return minuto;
	}

	public void setMinuto(int minuto) {
		this.minuto = minuto;
	}

	public int getSegundo() {
		return segundo;
	}

	public void setSegundo(int segundo) {
		this.segundo = segundo;
	}
	//retorna o tempo convertido para segundos
	public int cvtHora2Seg()
	{
		return this.getHora()*3600+this.getMinuto()*60+this.getSegundo();
	}
}
