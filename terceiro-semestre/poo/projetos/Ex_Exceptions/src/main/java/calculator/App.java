package calculator;

/**
 * Hello world!
 *
 */
public class App 
{
    public static void main( String[] args )
    {
		try{
			Calculadora.calcular(10, 0, '/');
		}
		catch(InvalidOperationException | ArithmeticException e){
			System.err.println(e.getMessage());
		}
    }
}
