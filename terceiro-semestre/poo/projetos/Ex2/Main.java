import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Digite o raio de um circulo: ");
		double raio = sc.nextDouble();
		System.out.printf("Diametro: %.2f\nÁrea: %.2f\nCircunferência: %.2f\n", 2 * raio,
				Math.PI * Math.pow(raio, 2), 2 * Math.PI * raio);
		sc.close();
	}
}
