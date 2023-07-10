package god.help.us;

import java.util.ArrayList;
import java.util.List;

public class Banco {
        private String nome;
        private int numero;
        private String cnpj;
        private String endereco;
        private List<Agencia> agencias;
        private Conta contaLogada = null;

        public Banco(String nome, int numero, String cnpj, String endereco) {
                setAgencias(new ArrayList<Agencia>());
                setNome(nome);
                setNumero(numero);
                setCnpj(cnpj);
                setEndereco(endereco);
        }

        public boolean logarCliente(int numAgencia, int numConta, String senha) {
                contaLogada = agencias.get(numAgencia).buscarConta(numConta, senha);
                return contaLogada == null ? false : true;
        }

        public void cadastrarAgencia(int numAgencia, Agencia agencia) {
                this.agencias.add(numAgencia, agencia);
        }

        public double saldo() {
                return contaLogada.getSaldo();
        }

        public void realizarDeposito(double deposito) {
                contaLogada.setSaldo(contaLogada.getSaldo() + deposito);
        }

        public boolean realizarSaque(double saque) {
                if (contaLogada.getSaldo() < saque)
                        return false;
                contaLogada.setSaldo(contaLogada.getSaldo() - saque);
                return true;
        }

        public boolean realizarTransferencia(int numAgencia, int numConta, double valor) {
                if (contaLogada.getSaldo() < valor)
                        return false;
                for (Conta conta : agencias.get(numAgencia).getContas()) {
                        if (conta.getNumero() != numConta)
                                continue;
                        conta.setSaldo(conta.getSaldo() + valor);
                        contaLogada.setSaldo(contaLogada.getSaldo() - valor);
                        return true;
                }
                return false;
        }

        public boolean pix(String cpf, double valor) {
                if (contaLogada.getSaldo() < valor)
                        return false;
                for (Agencia agencia : agencias) {
                        for (Conta conta : agencia.getContas()) {
                                if (!conta.getCpf().equals(cpf))
                                        continue;
                                System.out.println("Nome do destinatario: " + conta.getNome());
                                conta.setSaldo(conta.getSaldo() + valor);
                                contaLogada.setSaldo(contaLogada.getSaldo() - valor);
                                return true;
                        }
                }
                return false;
        }

        public void deslogarConta() {
                contaLogada = null;
        }

        /* Getters e Setters */

        public String getNome() {
                return nome;
        }

        private void setNome(String nome) {
                this.nome = nome;
        }

        public int getNumero() {
                return numero;
        }

        private void setNumero(int numero) {
                this.numero = numero;
        }

        public String getCnpj() {
                return cnpj;
        }

        private void setCnpj(String cnpj) {
                this.cnpj = cnpj;
        }

        public String getEndereco() {
                return endereco;
        }

        private void setEndereco(String endereco) {
                this.endereco = endereco;
        }

        public List<Agencia> getAgencias() {
                return agencias;
        }

        private void setAgencias(List<Agencia> agencias) {
                this.agencias = agencias;
        }

        public Conta getContaLogada() {
                return contaLogada;
        }

        public void setContaLogada(Conta contaLogada) {
                this.contaLogada = contaLogada;
        }
}
