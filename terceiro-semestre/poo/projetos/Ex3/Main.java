import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int n1;
		int n2;
		Scanner sc = new Scanner(System.in);
		System.out.println("Digite dois numeros: ");
		n1 = sc.nextInt();
		n2 = sc.nextInt();
		if (n1 % n2 == 0)
			System.out.println(n1 + " é multiplo de " + n2);
		else if (n2 % n1 == 0)
			System.out.println(n2 + " é multiplo de " + n1);
		else
			System.out.println("Não são multiplos");

		sc.close();
	}
}
