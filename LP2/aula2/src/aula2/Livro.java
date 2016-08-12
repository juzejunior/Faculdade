package aula2;

import javax.swing.JOptionPane;

public class Livro {

	private String nome, autor;
	private int numeroCopias, quantInicial;
	private int ano, valor;
        
        
        public Livro(String nome, String autor, int ano, int copias){
            this.nome = nome;
            this.autor = autor;
            this.ano = ano;
            this.numeroCopias = copias;
            this.quantInicial = copias;
            this.valor = 20;
        }
        
        public void comprarLivro(ContaBanco conta, int quant){
            if (conta.getSaldo() >= valor*quant && quant <= numeroCopias){
                conta.sacar(valor*quant);
                numeroCopias -= quant;
                JOptionPane.showMessageDialog(null,"Comprado com sucesso!");
            }else{
                JOptionPane.showMessageDialog(null,"POBRE DO CARALHO!");
            }
        }
	
	public String getNome() {
		return nome;
	}


	public void setNome(String nome) {
		this.nome = nome;
	}


	public String getAutor() {
		return autor;
	}


	public void setAutor(String autor) {
		this.autor = autor;
	}


	public int getNumeroCopias() {
		return numeroCopias;
	}


	public void setNumeroCopias(int numeroCopias) {
		this.numeroCopias = numeroCopias;
	}


	public int getAno() {
		return ano;
	}


	public void setAno(int ano) {
		this.ano = ano;
	}


	public void emprestar(int quantidade){
		if(quantidade <= this.getNumeroCopias()){
			this.numeroCopias -= quantidade;
		}else{
                    JOptionPane.showMessageDialog(null,"Sem copias suficientes disponiveis");
                }
	}
	
	public void devolver(int quantidade){
            if((numeroCopias+quantidade) > quantInicial){
                JOptionPane.showMessageDialog(null,"Quantidade a mais devolvida.");
            }else{
		this.numeroCopias += quantidade;
            }    
	}
	
	public void imprimir(){
		JOptionPane.showMessageDialog(null,"Nome: "+this.getNome()+"\nAutor: "+this.getAutor()+"\nAno: "+this.getAno()+"\nCopias: "+this.numeroCopias);
	}
	
}
