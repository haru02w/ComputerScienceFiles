package com.lucas.ribas;

/**
 * Shampoo
 */
public class Shampoo extends Produto {
	int irritabilidade;

	public Shampoo(String nome, double preco, int irritabilidade) {
		super(nome, preco);
		this.irritabilidade = irritabilidade;
	}

	@Override
	public int compareTo(Produto arg0) {
		Leite leite = (Leite) arg0;
		return (leite.getPreco() / irritabilidade < this.getPreco() / irritabilidade) ? 1
				: (leite.getPreco() / irritabilidade > this.getPreco() / irritabilidade) ? -1 : 0;
	}

}
