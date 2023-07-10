public class Vendedor {
	private double salario;

	public Vendedor(int vendas) {
		this.setSalario(vendas);
	}

	public double getSalario() {
		return salario;
	}

	public void setSalario(int vendas) {
		this.salario = 200 + (vendas * 9 / 100);
	}

}
