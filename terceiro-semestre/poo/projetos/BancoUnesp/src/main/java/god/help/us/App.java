package god.help.us;

public class App {
    final static String path = "./files/";

    public static void main(String[] args) {
        DisplayBanco db = new DisplayBanco(path + "banco.txt", path + "agencias.txt", path + "contas.txt");
        db.login();
    }
}
