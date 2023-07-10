import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Double e = 0.0;
		System.out.println("Digite quantos termos de precisão da constante e (maximo 34): ");
		int termos = sc.nextInt();
		for (int i = 0; i < termos; i++)
			e += 1 / factorial(i);
		System.out.println("O valor de e aproximado é de " + e);

		sc.close();

	}

	private static double factorial(int x) {
		for (int i = x - 1; i > 0; i--)
			x *= i;

		return x == 0 ? 1 : x;
	}
}
