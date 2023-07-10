package com.lucas.ribas;

/**
 * Biscoito
 */
public class Biscoito extends Produto {

	int cancer;

	public Biscoito(String nome, double preco, int cancer) {
		super(nome, preco);
		this.cancer = cancer;
	}

	@Override
	public int compareTo(Produto arg0) {
		Biscoito biscoito = (Biscoito) arg0;
		return (biscoito.getPreco() / cancer < this.getPreco() / cancer) ? 1
				: (biscoito.getPreco() / cancer > this.getPreco() / cancer) ? -1 : 0;
	}

}
