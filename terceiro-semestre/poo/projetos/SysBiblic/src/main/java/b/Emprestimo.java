package b;

import java.time.LocalDate;

public class Emprestimo {
	private Item item;
	private Usuario usuario;

	private LocalDate dataEmprestimo;
	private LocalDate dataDevolucaoPrevista;
	private LocalDate dataDevolucaoReal = null;

	public Emprestimo(int diasEmprestado, Usuario usuario, Item item) {
		this.dataEmprestimo = LocalDate.now(); /* Debug.QDiaEHoje(); */
		this.dataDevolucaoPrevista = this.dataEmprestimo.plusDays(diasEmprestado);
		this.item = item;
		this.usuario = usuario;
	}

	public void setDataDevolucaoReal() {
		this.dataDevolucaoReal = LocalDate.now();/* Debug.QDiaEHoje(); */
	}

	public LocalDate getDataDevolucaoReal() {
		return dataDevolucaoReal;
	}

	public Item getItem() {
		return item;
	}

	public LocalDate getDataEmprestimo() {
		return dataEmprestimo;
	}

	public LocalDate getDataDevolucaoPrevista() {
		return dataDevolucaoPrevista;
	}

	public Usuario getUsuario() {
		return usuario;
	}
}
