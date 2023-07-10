package b;

public class Revista extends Item {
	private int volume;
	private int numero;

	public Revista(String titulo, String autor, int anoPublicacao, int qtdDisponivel, int volume, int numero) {
		super.setTitulo(titulo);
		super.setAutor(autor);
		super.setAnoPublicacao(anoPublicacao);
		super.setQtdDisponivel(qtdDisponivel);
		this.volume = volume;
		this.numero = numero;
	}

	public int getVolume() {
		return volume;
	}

	public void setVolume(int volume) {
		this.volume = volume;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
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
