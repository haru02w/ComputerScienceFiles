import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Digite um caracter: ");
		char c = sc.next().charAt(0);
		System.out.printf("O codigo na tabela ASCII de '%c' é %d\n", c, (int) c);
		sc.close();
	}
}
