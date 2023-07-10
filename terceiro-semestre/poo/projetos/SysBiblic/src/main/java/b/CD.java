package b;

public class CD extends Item {
	private int volume;
	private String gravadora;

	public CD(String titulo, String compositor, int anoPublicacao, int qtdDisponivel, int volume,
			String gravadora) {
		super.setTitulo(titulo);
		super.setAutor(compositor);
		super.setAnoPublicacao(anoPublicacao);
		super.setQtdDisponivel(qtdDisponivel);
		this.volume = volume;
		this.gravadora = gravadora;
	}

	public String getGravadora() {
		return gravadora;
	}

	public void setGravadora(String gravadora) {
		this.gravadora = gravadora;
	}

	public int getVolume() {
		return volume;
	}

	public void setVolume(int volume) {
		this.volume = volume;
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
