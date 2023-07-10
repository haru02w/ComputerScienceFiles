package god.help.us;

import java.io.File;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DisplayBanco {
        private Banco meuBanco;

        Scanner sc = null;

        public DisplayBanco(String bancoNome, String agenciasNome, String contasNome) {
                /* **************** Banco **************** */
                Banco banco = null;
                File arquivo = new File(bancoNome);
                try {
                        sc = new Scanner(arquivo);
                } catch (Exception e) {
                        Logger.getLogger(App.class.getName()).log(Level.SEVERE, null, e);
                }

                if (sc.hasNextLine()) {
                        String[] campos = sc.nextLine().split("#");

                        banco = new Banco(
                                        /* nome */ campos[0],
                                        /* numero */ Integer.valueOf(campos[1]),
                                        /* cnpj */ campos[2],
                                        /* endereco */ campos[3]);
                }
                meuBanco = banco;

                if (meuBanco == null)
                        return;

                /* **************** Agencias **************** */
                arquivo = new File(agenciasNome);
                try {
                        sc = new Scanner(arquivo);
                } catch (Exception e) {
                        Logger.getLogger(App.class.getName()).log(Level.SEVERE, null, e);
                }

                while (sc.hasNextLine()) {
                        String linha = sc.nextLine();
                        String[] campos = linha.split("#");

                        Agencia agencia = new Agencia(
                                        /* nome */ campos[0],
                                        /* codigo */ Integer.valueOf(campos[1]),
                                        /* endereco */ campos[2]);
                        meuBanco.cadastrarAgencia(Integer.valueOf(campos[1]), agencia);
                }

                if (meuBanco.getAgencias().size() == 0)
                        return;

                /* **************** Contas **************** */
                arquivo = new File(contasNome);

                try {
                        sc = new Scanner(arquivo);
                } catch (Exception e) {
                        Logger.getLogger(App.class.getName()).log(Level.SEVERE, null, e);
                }

                while (sc.hasNextLine()) {
                        String linha = sc.nextLine();
                        String[] campos = linha.split("#");

                        Conta conta = new Conta(
                                        /* nome */ campos[0],
                                        /* nascimento */ campos[1],
                                        /* endereco */ campos[2],
                                        /* cpf */ campos[3],
                                        /* saldo */ Double.valueOf(campos[4]),
                                        /* numero */ Integer.valueOf(campos[6]),
                                        /* senha */ campos[7]);
                        /* numero agencia como indice */
                        meuBanco.getAgencias().get(Integer.valueOf(campos[5])).getContas().add(conta);
                }

        }

        public void login() {
                sc = new Scanner(System.in);
                for (;;) {

                        System.out.println("Bem vindo ao banco Unesp!");

                        System.out.println("Digite o numero da Agencia: ");
                        int numAgencia = sc.nextInt();

                        System.out.println("Digite o numero da conta: ");
                        int numConta = sc.nextInt();

                        sc.nextLine(); // limpar o \n do buffer

                        System.out.println("Digite a senha da conta: ");
                        String senha = sc.nextLine().trim();

                        if (meuBanco.logarCliente(numAgencia, numConta, senha) == true)
                                telaUsuario();
                        else
                                System.out.println("Campos incorretos. Tente novamente");
                }
        }

        private void telaUsuario() {
                System.out.println("Bem vindo " + meuBanco.getContaLogada().getNome() + "!");
                for (;;) {

                        System.out.println("Selecione a opção desejada: ");
                        System.out.println("1 - Consultar saldo");
                        System.out.println("2 - Depósito");
                        System.out.println("3 - Saque");
                        System.out.println("4 - Transferencia");
                        System.out.println("5 - Pix");
                        System.out.println("6 - Sair");
                        System.out.println();

                        switch (sc.nextInt()) {
                                case 1:
                                        operacaoSaldo();
                                        break;
                                case 2:
                                        operacaoDeposito();
                                        break;
                                case 3:
                                        operacaoSaque();
                                        break;
                                case 4:
                                        operacaoTransferencia();
                                        break;
                                case 5:
                                        operacaoPix();
                                        break;
                                case 6:
                                        operacaoSair();
                                        return;
                        }
                }

        }

        private void operacaoSair() {
                meuBanco.deslogarConta();
        }

        private void operacaoPix() {
                System.out.println("Digite a chave pix (CPF): ");
                sc.nextLine();
                String pix = sc.nextLine();
                System.out.println("Digite o valor: ");
                double valor = sc.nextDouble();

                if (meuBanco.pix(pix, valor))
                        operacaoSaldo();
                else
                        System.out.println("Destinatario não encontrado ou Saldo insuficiente");

        }

        private void operacaoTransferencia() {
                System.out.println("Digite o numero da agencia: ");
                int agencia = sc.nextInt();
                System.out.println("Digite o numero da conta: ");
                int conta = sc.nextInt();
                System.out.println("Digite o valor à transferir: ");
                double valor = sc.nextDouble();

                if (meuBanco.realizarTransferencia(agencia, conta, valor) && valor > 0)
                        operacaoSaldo();
                else
                        System.out.println("Destinatario não encontrado ou Saldo insuficiente");
        }

        private void operacaoSaldo() {
                System.out.println("Seu saldo é de R$" + meuBanco.saldo());
        }

        private void operacaoSaque() {
                System.out.println("Digite a quantidade à sacar: ");
                double saque = sc.nextDouble();
                if (meuBanco.realizarSaque(saque) && saque > 0)
                        operacaoSaldo();
                else
                        System.out.println("Saldo insuficiente");
        }

        private void operacaoDeposito() {
                System.out.println("Digite a quantidade à depositar: ");
                double deposito = sc.nextDouble();
                if (deposito <= 0) {
                        System.out.println("Valor Invalido");
                        return;
                }
                meuBanco.realizarDeposito(deposito);
                operacaoSaldo();
        }
}
