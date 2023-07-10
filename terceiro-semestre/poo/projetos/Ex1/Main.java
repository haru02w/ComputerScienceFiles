import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int arr[] = new int[3];
		int soma = 0;
		int produto = 1;
		int maior = 0, menor = Integer.MAX_VALUE;
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 3; i++) {
			System.out.println("Digite o " + (i + 1) + "° numero: ");
			arr[i] = sc.nextInt();
			soma += arr[i];
			produto *= arr[i];
			menor = arr[i] < menor ? arr[i] : menor;
			maior = arr[i] > maior ? arr[i] : maior;
		}

		System.out.println("Soma: " + soma);
		System.out.println("Media: " + (soma / 3.0));
		System.out.println("Produto: " + produto);
		System.out.println("Menor: " + menor);
		System.out.println("Maior: " + maior);
		sc.close();
	}
}
