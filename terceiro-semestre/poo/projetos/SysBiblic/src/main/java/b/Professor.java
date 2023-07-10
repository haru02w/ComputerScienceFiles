package b;

public class Professor extends Usuario {
	private String departamento;
	private String titulacao;

	public Professor(String nome, String matricula, String departamento, String titulacao) {
		super.setNome(nome);
		super.setMatricula(matricula);
		this.departamento = departamento;
		this.titulacao = titulacao;
	}

	@Override
	double calcularMulta(Emprestimo emprestimo) {
		return 1.25 * super.calcularMulta(emprestimo);
	}

	public String getDepartamento() {
		return departamento;
	}

	public void setDepartamento(String departamento) {
		this.departamento = departamento;
	}

	public String getTitulacao() {
		return titulacao;
	}

	public void setTitulacao(String titulacao) {
		this.titulacao = titulacao;
	}
}
