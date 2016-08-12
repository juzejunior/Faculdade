import java.util.ArrayList;

public class Cliente {

	private String nome;
	private String cpf;
	private String telefone;
	private String email;
	private ArrayList<Automovel> autos;
	
	public Cliente(String nome, String cpf, String telefone, String email)
	{
		this.nome = nome;
		this.cpf = cpf;
		this.telefone = telefone;
		this.email = email;
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}	
	
	public boolean substituirCarro(Automovel atual, Automovel subs)
	{
		if(subs.getAno() <= atual.getAno() && subs.getCategoria().equals(atual.getCategoria()))
		{
			return true;
		}
		return false;
	}
	
	public int quantCarCat(String categoria)
	{
		int cont = 0;
		for(Automovel i : this.autos)
		{
			if(i.getCategoria().equals(categoria)) cont += 1;
		}
		return cont;
	}
}
