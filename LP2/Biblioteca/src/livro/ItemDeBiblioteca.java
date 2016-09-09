package livro;

public interface ItemDeBiblioteca {
	int numMaxDeDias = 14;
	
	abstract void emprestimo();
	abstract void devolucao();
	
}
