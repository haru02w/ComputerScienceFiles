package god.help.us;

import java.util.ArrayList;
import java.util.List;

public class Agencia {
        private String nome;
        private int codigo;
        private String endereco;
        private List<Conta> contas;

        public Agencia(String nome, int codigo, String endereco) {
                setContas(new ArrayList<Conta>());
                setNome(nome);
                setCodigo(codigo);
                setEndereco(endereco);
        }

        public Conta buscarConta(int numConta, String senha) {
                for (Conta conta : contas)
                        if (conta.getNumero() == numConta && conta.validarSenha(senha))
                                return conta;
                return null;
        }

        /* Getters e Setters */
        public String getNome() {
                return nome;
        }

        private void setNome(String nome) {
                this.nome = nome;
        }

        public int getCodigo() {
                return codigo;
        }

        private void setCodigo(int codigo) {
                this.codigo = codigo;
        }

        public String getEndereco() {
                return endereco;
        }

        private void setEndereco(String endereco) {
                this.endereco = endereco;
        }

        public List<Conta> getContas() {
                return contas;
        }

        private void setContas(List<Conta> contas) {
                this.contas = contas;
        }
}
