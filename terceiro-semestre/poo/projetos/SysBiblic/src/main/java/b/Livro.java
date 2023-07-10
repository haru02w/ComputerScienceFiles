package b;

public class Livro extends Item {
	private String editora;
	private String isbn;

	public Livro(String titulo, String autor, int anoPublicacao, int qtdDisponivel, String editora, String isbn) {
		super.setTitulo(titulo);
		super.setAutor(autor);
		super.setAnoPublicacao(anoPublicacao);
		super.setQtdDisponivel(qtdDisponivel);
		this.editora = editora;
		this.isbn = isbn;
	}

	public String getEditora() {
		return editora;
	}

	public void setEditora(String editora) {
		this.editora = editora;
	}

	public String getIsbn() {
		return isbn;
	}

	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}

	@Override
	public Emprestimo emprestimo(Usuario usuario, int diasEmprestado) {
		return super.emprestimo(usuario, diasEmprestado);
	}

	@Override
	public void devolucao(Emprestimo emprestimo) {
		super.devolucao(emprestimo);
	}
}
