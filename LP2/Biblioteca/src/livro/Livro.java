package livro;

public class Livro {

	private String titulo, autor;
	private int numPaginas, anoEdicao;
	private boolean emprestado;
	
	public Livro(String titulo, String autor, int numPaginas, int anoEdicao, boolean emprestado) {
		this.titulo = titulo;
		this.autor = autor;
		this.numPaginas = numPaginas;
		this.anoEdicao = anoEdicao;
		this.emprestado = emprestado;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}

	public int getNumPaginas() {
		return numPaginas;
	}

	public void setNumPaginas(int numPaginas) {
		this.numPaginas = numPaginas;
	}

	public int getAnoEdicao() {
		return anoEdicao;
	}

	public void setAnoEdicao(int anoEdicao) {
		this.anoEdicao = anoEdicao;
	}

	public boolean isEmprestado() {
		return emprestado;
	}

	public void setEmprestado(boolean emprestado) {
		this.emprestado = emprestado;
	}

	@Override
	public String toString() {
		return "Livro [titulo=" + titulo + ", autor=" + autor + ", numPaginas=" + numPaginas + ", anoEdicao="
				+ anoEdicao + ", emprestado=" + emprestado + "]";
	}
}
