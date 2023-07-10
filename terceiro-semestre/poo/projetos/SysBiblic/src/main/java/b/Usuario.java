package b;

import java.time.temporal.ChronoUnit;
import java.util.LinkedList;
import java.util.List;

public abstract class Usuario {
	private String nome;
	private String matricula;
	private List<Emprestimo> emprestimos = new LinkedList<>();

	double calcularMulta(Emprestimo emprestimo) {
		/*
		 * return 5.0 * (emprestimo.getDataDevolucaoReal().toEpochDay()
		 * - emprestimo.getDataDevolucaoPrevista().toEpochDay());
		 */
		if (emprestimo.getDataDevolucaoPrevista().toEpochDay() >= emprestimo.getDataDevolucaoReal().toEpochDay())
			return 0;
		return 5.0 * emprestimo.getDataDevolucaoPrevista()
				.until(emprestimo.getDataDevolucaoReal(), ChronoUnit.DAYS);
	}

	public Emprestimo realizarEmprestimo(Item item, int diasEmprestado) {
		Emprestimo emprestimo = item.emprestimo(this, diasEmprestado);
		if (emprestimo == null)
			return emprestimo;
		emprestimos.add(emprestimo);
		return emprestimo;
	}

	public double realizarDevolucao(Item item) {
		for (Emprestimo emprestimo : emprestimos) {
			if (emprestimo.getItem() == item) {
				emprestimos.remove(emprestimo);
				item.devolucao(emprestimo);
				return calcularMulta(emprestimo);
			}
		}
		return -1;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getMatricula() {
		return matricula;
	}

	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}

	public List<Emprestimo> getEmprestimos() {
		return emprestimos;
	}

	public void setEmprestimos(List<Emprestimo> emprestimos) {
		this.emprestimos = emprestimos;
	}

}
