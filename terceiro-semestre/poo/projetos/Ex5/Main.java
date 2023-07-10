import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		double n[] = new double[15];
		double maiores[];
		Scanner sc = new Scanner(System.in);

		System.out.println("Digite 15 numeros: ");
		for (int i = 0; i < 15; i++)
			n[i] = sc.nextDouble();

		maiores = maiores(n);
		System.out.println("Os 2 maiores numeros são: " + maiores[0] + " e " + maiores[1]);
		sc.close();
	}

	private static double[] maiores(double[] n) {
		double maiores[] = new double[2];
		maiores[0] = 0;
		maiores[1] = 0;
		for (int i = 0; i < 15; i++) {
			if (maiores[0] < n[i]) {
				maiores[1] = maiores[0];
				maiores[0] = n[i];
			}
		}
		return maiores;

	}

}
