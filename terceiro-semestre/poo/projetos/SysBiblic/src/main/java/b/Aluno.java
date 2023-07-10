package b;

public class Aluno extends Usuario {
	private String curso;
	private String periodo;

	public Aluno(String nome, String matricula, String curso, String periodo) {
		super.setNome(nome);
		super.setMatricula(matricula);
		this.curso = curso;
		this.periodo = periodo;
	}

	// padrão é 5 reais por dia
	@Override
	double calcularMulta(Emprestimo emprestimo) {
		return super.calcularMulta(emprestimo);
	}

	public String getCurso() {
		return curso;
	}

	public void setCurso(String curso) {
		this.curso = curso;
	}

	public String getPeriodo() {
		return periodo;
	}

	public void setPeriodo(String periodo) {
		this.periodo = periodo;
	}
}
