package b;

import java.time.LocalDate;
import java.util.Scanner;

public class Debug {
	static Scanner sc = null;

	public static LocalDate QDiaEHoje() {
		System.out.println("Digite q dia é hoje no formato 12/34/5678");
		String string[] = sc.nextLine().split("/");
		return LocalDate.of(Integer.parseInt(string[2]),
				Integer.parseInt(string[1]),
				Integer.parseInt(string[0]));
	}
}
