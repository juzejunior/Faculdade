package ligacao;

import java.util.ArrayList;

public class ContaTelefonica {

	private int mes, ano, contrato;
	private ArrayList<Ligacao> ligacoes;
	
	public ContaTelefonica(int mes, int ano, int contrato) {
		this.mes = mes;
		this.ano = ano;
		this.contrato = contrato;
		this.ligacoes = new ArrayList<Ligacao>();
	}
	
	public int getMes() {
		return mes;
	}
	
	public void setMes(int mes) {
		if(mes >= 1 && mes <= 12) this.mes = mes;
	}
	
	public int getAno() {
		return ano;
	}
	
	public void setAno(int ano) {
		this.ano = ano;
	}
	
	public int getContrato() {
		return contrato;
	}
	
	public void setContrato(int contrato) {
		if(contrato >= 0)
			this.contrato = contrato;
	}
	
	public ArrayList<Ligacao> getLigacoes() {
		return ligacoes;
	}
	
	public void addLigacao(Ligacao ligacao) {
		if(ligacao != null)
			this.ligacoes.add(ligacao);
		else System.err.println("Passe uma ligação válida!");
	}	
	
	public double valorConta()
	{
		double valor = 0;
		for(Ligacao i : this.getLigacoes())
		{
			valor += i.getValorLigacao();
		}
		return valor;
	}
	
	public double valorConta(String destino)
	{
		double valor = 0;
		for(Ligacao i : this.getLigacoes())
		{
			if(i.getLocalDest().equals(destino)) valor += i.getValorLigacao();
		}
		return valor;
	}
	
	public int numLigacoes(String numero)
	{
		int quant = 0;
		for(Ligacao i : this.getLigacoes())
		{
			if(i.getNumDest().equals(numero) || i.getNumOrigem().equals(numero))
			{
				quant += 1;
			}
		}
		return quant;
	}
}
