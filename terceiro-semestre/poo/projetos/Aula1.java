import java.util.Scanner;

/**
 * Hello world!
 *
 */
public class Aula1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Quantas linhas tem a matriz 1: ");
		int lines1 = sc.nextInt();
		System.out.println("Quantas colunas tem a matriz 1: ");
		int columns1 = sc.nextInt();

		System.out.println("Quantas linhas tem a matriz 2: ");
		int lines2 = sc.nextInt();
		System.out.println("Quantas colunas tem a matriz 2: ");
		int columns2 = sc.nextInt();

		if (columns1 != lines2) {
			System.out.println("Matrizes não multiplicaveis.\n");
			sc.close();
			return;
		}
		sc.close();
	}
}
