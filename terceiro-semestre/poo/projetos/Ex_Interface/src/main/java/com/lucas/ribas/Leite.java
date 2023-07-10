package com.lucas.ribas;

/**
 * Leite
 */
public class Leite extends Produto {

	int validade;

	public Leite(String nome, double preco, int validade) {
		super(nome, preco);
		this.validade = validade;
	}

	@Override
	public int compareTo(Produto arg0) {
		Leite leite = (Leite) arg0;
		return (leite.getPreco() / validade < this.getPreco() / validade) ? 1
				: (leite.getPreco() / validade > this.getPreco() / validade) ? -1 : 0;
	}
}
