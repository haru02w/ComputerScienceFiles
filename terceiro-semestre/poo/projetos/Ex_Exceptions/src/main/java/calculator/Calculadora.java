package calculator;

public class Calculadora {

	public static double calcular(double a, double b, char op)
			throws ArithmeticException, InvalidOperationException {
		switch (op) {
			case '+':
				return a + b;

			case '-':
				return a - b;

			case '*':
				return a * b;

			case '/':
				if (b == 0.0)
					throw new ArithmeticException("Divisão por zero");
				return a / b;

			default:
				throw new InvalidOperationException("Operação invalida");
		}
	}
}
