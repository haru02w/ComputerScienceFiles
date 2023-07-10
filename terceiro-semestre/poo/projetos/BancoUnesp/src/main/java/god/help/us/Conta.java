package god.help.us;

public class Conta {
        private String nome;
        private String dataNascimento;
        private String endereco;
        private String cpf;
        private double saldo;
        private int numero;
        private String senha;

        public Conta(String nome, String dataNascimento, String endereco, String cpf, double saldo, int numero,
                        String senha) {
                this.nome = nome;
                this.dataNascimento = dataNascimento;
                this.endereco = endereco;
                this.cpf = cpf;
                this.saldo = saldo;
                this.numero = numero;
                this.senha = senha;
        }

        public boolean validarSenha(String senha) {
                return this.senha.equals(senha);
        }

        /* Getters e Setters */
        public String getNome() {
                return nome;
        }

        public void setNome(String nome) {
                this.nome = nome;
        }

        public String getDataNascimento() {
                return dataNascimento;
        }

        public void setDataNascimento(String dataNascimento) {
                this.dataNascimento = dataNascimento;
        }

        public String getEndereco() {
                return endereco;
        }

        public void setEndereco(String endereco) {
                this.endereco = endereco;
        }

        public String getCpf() {
                return cpf;
        }

        public void setCpf(String cpf) {
                this.cpf = cpf;
        }

        public double getSaldo() {
                return saldo;
        }

        public void setSaldo(double saldo) {
                this.saldo = saldo;
        }

        public int getNumero() {
                return numero;
        }

        public void setNumero(int numero) {
                this.numero = numero;
        }
}
