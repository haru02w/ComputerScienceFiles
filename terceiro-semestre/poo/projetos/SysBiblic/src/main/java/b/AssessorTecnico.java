package b;

public class AssessorTecnico extends Usuario {
	private String sessao; // Academica, Pos-graduação, Graduação e Administrativa

	public AssessorTecnico(String nome, String matricula, String sessao) {
		super.setNome(nome);
		super.setMatricula(matricula);
		this.sessao = sessao;
	}

	@Override
	double calcularMulta(Emprestimo emprestimo) {
		return 1.15 * super.calcularMulta(emprestimo);
	}

	public String getSessao() {
		return sessao;
	}

	public void setSessao(String sessao) {
		this.sessao = sessao;
	}

}
