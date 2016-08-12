package ligacao;

import hora.Hora;

public class Ligacao {

	private String numOrigem, localOrigem, numDest, localDest;
	private double valorLigacao;
	private Hora inicio, fim;
	
	public Ligacao(String numOrigem, String localOrigem, String numDest, String localDest, Hora inicio, Hora fim)
	{
		this.numOrigem = numOrigem;
		this.localOrigem = localOrigem;
		this.numDest = numDest;
		this.localDest = localDest;
		this.inicio = inicio;
		this.fim = fim;
	}

	public Ligacao(String numOrigem, String localOrigem, String numDest, String localDest, Hora inicio)
	{
		this(numOrigem, localOrigem, numDest, localDest, inicio, null);
	}
	
	public String getNumOrigem() 
	{
		return numOrigem;
	}

	public void setNumOrigem(String numOrigem) 
	{
		this.numOrigem = numOrigem;
	}

	public String getLocalOrigem()
	{
		return localOrigem;
	}

	public void setLocalOrigem(String localOrigem) 
	{
		this.localOrigem = localOrigem;
	}

	public String getNumDest() 
	{
		return numDest;
	}

	public void setNumDest(String numDest)
	{
		this.numDest = numDest;
	}

	public String getLocalDest() 
	{
		return localDest;
	}

	public void setLocalDest(String localDest)
	{
		this.localDest = localDest;
	}
	
	//valor da ligacao
	public double getValorLigacao()
	{
		float resto;
		int segundos = fim.cvtHora2Seg() - inicio.cvtHora2Seg();
		float minutoTotal = segundos/60;
		resto = segundos%60;
		//se ultrapassou o minuto
		if(resto != 0)
		{
			return minutoTotal+1;
		}
		return minutoTotal;
	}
	
	//verifica se um numero informado pertence a chamada
	public boolean verificaTel(String telefone)
	{
		if(telefone.equals(this.getNumOrigem()) || telefone.equals(this.getNumDest()))
		{
			return true;
		}
		
		return false;
	}
}
