package livro;

public class Movimentacao extends Livro implements ItemDeBiblioteca{

	public Movimentacao(String titulo, String autor, int numPaginas, int anoEdicao, boolean emprestado) {
		super(titulo, autor, numPaginas, anoEdicao, emprestado);
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public void emprestimo() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void devolucao() {
		// TODO Auto-generated method stub
		
	}

}
