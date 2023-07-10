package b;

public interface Emprestavel {
	public Emprestimo emprestimo(Usuario usuario, int diasEmprestado);

	public void devolucao(Emprestimo emprestimo);
}
