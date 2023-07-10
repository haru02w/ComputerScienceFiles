package b;

import java.io.File;
import java.util.Scanner;

public class App {
	static Scanner sc = null;
	final static String filepath = "./files" + File.separator + "items.txt";

	public static void main(String[] args) {
		InterfaceComandos cli = new InterfaceComandos(filepath);
		cli.menu();
	}

}
