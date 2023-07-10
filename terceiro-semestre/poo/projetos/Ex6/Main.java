import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int i = 0;; i++) {
			System.out.println("Digite as vendas do " + (i + 1) + "° vendedor: ");
			int tmp = sc.nextInt();
			if (tmp == -1)
				break;
			Vendedor vendedor = new Vendedor(tmp);
			System.out.println("O salario do " + (i + 1) + "° vendedor é " + vendedor.getSalario()
					+ " reais.");
		}
		sc.close();
	}
}
