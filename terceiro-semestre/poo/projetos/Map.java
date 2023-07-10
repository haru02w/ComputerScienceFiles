import java.io.File;
import java.util.Scanner;

public class Map {
	public static void main(String[] args) {
		if (args.length != 2)
			return;
		File file = new File(args[1]);
		try {
			Scanner sc = new Scanner(file);
		} catch (FileNotFoundException e) {
			return;
		}

		while (read.hasNext()) {
			
		}
		sc.close();

	}
}
