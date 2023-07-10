package b;

public abstract class Item implements Emprestavel {
	private String titulo;
	private String autor;
	private int anoPublicacao;
	private int qtdDisponivel;

	public Emprestimo emprestimo(Usuario usuario, int diasEmprestado) {
		if (this.qtdDisponivel <= 0)
			return null;
		this.qtdDisponivel--;
		return new Emprestimo(diasEmprestado, usuario, this);
	}

	public void devolucao(Emprestimo emprestimo) {
		emprestimo.setDataDevolucaoReal();
		this.qtdDisponivel++;
		return;
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

	public int getAnoPublicacao() {
		return anoPublicacao;
	}

	public void setAnoPublicacao(int anoPublicacao) {
		this.anoPublicacao = anoPublicacao;
	}

	public int getQtdDisponivel() {
		return qtdDisponivel;
	}

	public void setQtdDisponivel(int qtdDisponivel) {
		this.qtdDisponivel = qtdDisponivel;
	}

}
