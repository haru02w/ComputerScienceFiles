public class Aula2 {
	public static void main(String[] args) {
		Integer intObj = Integer.valueOf(123);
		Long longObj = Long.valueOf(123);
		Double doubleObj = Double.valueOf(12.345);
		Boolean boolObj = Boolean.valueOf(true);
		Object[] objArray = { intObj, longObj, doubleObj, boolObj };

		for (int i = 0; i < objArray.length; i++) {
			if (objArray[i] instanceof Number) {
				System.out.println(objArray[i].toString() + " é um Numero");
			} else {
				System.out.println(objArray[i].toString() + " não é um Numero");
			}
		}
	}
}
