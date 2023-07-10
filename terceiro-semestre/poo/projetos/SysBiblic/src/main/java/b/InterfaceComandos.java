package b;

import java.io.File;
import java.io.FileNotFoundException;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/*
 * O sistema de biblioteca deve possuir as seguintes funcionalidades:
 *
 * 1. Cadastro de usuarios e itens;
 *
 * 2. Emprestimo e devolucao de itens: o sistema gerencia o processo de emprestimo e devolucao de itens.
 * Os usuarios podem emprestar itens disponıveis, e o sistema registra a data de emprestimo, o prazo de
 * devolucao e o usuario responsavel. Ao devolver um item, o sistema verifica se o prazo de devolucao
 * foi cumprido e, se necessario, aplica multas por atraso.
 *
 * 3. Busca por itens disponıveis: busca pelo nome do item, listando os dados do item como quantidade
 * disponıvel, etc.
 *
 * 4. Listagem de itens emprestados por usuario: digite a matrıcula do usuario para listagem;
 *
 * 5. Aplicacao de multas por atraso na devolucao.
*/

/*
 * O sistema deve tratar, pelo menos, as seguintes exceções:
 ** Tentativa de empréstimo de um item indisponível;
 ** Tentativa de devolução de um item não emprestado;
 ** Tentativa de cadastro de um usuário ou item com informações inválidas.
*/
public class InterfaceComandos {
	// lista de todos os usuarios cadastrados
	private List<Usuario> usuarios = new LinkedList<>();
	// lista de todos os itens cadastrados
	private List<Item> itens = new LinkedList<>();
	// lista de todos os emprestimos realizados no sistema
	private List<Emprestimo> emprestimos = new LinkedList<>();

	private Scanner sc = null;

	// construtor por arquivo
	public InterfaceComandos(String filename) {
		try {
			sc = new Scanner(new File(filename));
		} catch (FileNotFoundException e) {
			System.err.println("Arquivo " + filename + " não encontrado!");
			return;
		}
		while (sc.hasNextLine()) {
			String[] campos = sc.nextLine().split("#");
			if (campos[0].equalsIgnoreCase("CD")) {
				CD item = new CD(
						/* Titulo do CD */ campos[1],
						/* Compositor do CD */ campos[2],
						/* Ano de publicacao */ Integer.valueOf(campos[3]),
						/* Quantidade disponivel */ Integer.valueOf(campos[4]),
						/* Volume */ Integer.valueOf(campos[5]),
						/* Gravadora do CD */ campos[6]);
				itens.add(item);
			} else if (campos[0].equalsIgnoreCase("Revista")) {
				Revista item = new Revista(
						/* Titulo da Revista */ campos[1],
						/* Autor da Revista */ campos[2],
						/* Ano de publicacao */ Integer.valueOf(campos[3]),
						/* Quantidade disponivel */ Integer.valueOf(campos[4]),
						/* Volume */ Integer.valueOf(campos[5]),
						/* Numero */ Integer.valueOf(campos[6]));
				itens.add(item);
			} else if (campos[0].equalsIgnoreCase("Livro")) {
				Livro item = new Livro(
						/* Titulo do livro */ campos[1],
						/* Autor do livro */ campos[2],
						/* Ano de publicacao */ Integer.valueOf(campos[3]),
						/* Quantidade disponivel */ Integer.valueOf(campos[4]),
						/* Editora do livro */ campos[5],
						/* ISBN */ campos[6]);
				itens.add(item);
			}
		}
	}

	public static Integer tryParseInt(String text) {
		try {
			return Integer.parseInt(text);
		} catch (NumberFormatException e) {
			return -1;
		}
	}

	public void menu() {
		sc = new Scanner(System.in);

		LocalTime tempo = LocalTime.now();
		String intro = null;
		if (tempo.getHour() >= 6 && tempo.getHour() < 12)
			intro = "Bom dia!";
		else if (tempo.getHour() >= 12 && tempo.getHour() < 18)
			intro = "Boa tarde!";
		else
			intro = "Boa noite!";
		tempo = null;

		System.out.println(intro + " Bem vindo ao SysBiblic.");
		for (;;) {
			System.out.println("Selecione a opção desejada:\n" +
					"0) Encerrar programa\n" +
					"1) Cadastrar Usuario\n" +
					"2) Cadastrar Item\n" +
					"3) Pesquisar Usuario\n" +
					"4) Pesquisar Item\n" +
					"5) Listar Devoluções Atrasadas\n");

			switch (tryParseInt(sc.nextLine())) {
				case 0:
					return;
				case 1:
					menuCadastrarUsuario();
					break;
				case 2:
					menuCadastrarItem();
					break;
				case 3:
					menuPesquisarUsuario();
					break;
				case 4:
					menuPesquisarItem();
					break;
				case 5:
					menuDevolucoesAtrasadas();
					break;
				default:
					System.out.println("Opção invalida");
					break;
			}

			/*
			 * System.out.printf("Selecione a opção desejada:\n"+
			 * "0) Encerrar programa\n"+
			 * "1) Cadastrar Usuario\n"+
			 * "2) Cadastrar Item\n"+
			 * "3) Registrar Emprestimo\n"+
			 * "4) Registrar Devolução\n"+
			 * "5) Pesquisar Itens\n"+
			 * "6) Listar Itens Emprestados\n"+
			 * "7) Aplicar Multas\n");
			 */
		}
	}

	private void menuCadastrarUsuario() {
		Usuario usuario = null;

		System.out.println("Digite o nome do Usuario:");
		String nome = sc.nextLine().strip();
		System.out.println("Digite a matricula do Usuario:");
		String matricula = sc.nextLine().strip();

		System.out.println("Qual o tipo de Usuario?\n" +
				"1) Aluno\n" +
				"2) Professor\n" +
				"3) Assessor Tecnico\n");
		switch (tryParseInt(sc.nextLine())) {
			case 1 -> {
				System.out.println("Digite o curso: ");
				String curso = sc.nextLine().strip();
				System.out.println("Digite o periodo: ");
				String periodo = sc.nextLine().strip();
				usuario = new Aluno(nome, matricula, curso, periodo);
			}
			case 2 -> {
				System.out.println("Digite o departamento: ");
				String departamento = sc.nextLine().strip();
				System.out.println("Digite a titulação: ");
				String titulacao = sc.nextLine().strip();
				usuario = new Professor(nome, matricula, departamento, titulacao);
			}
			case 3 -> {
				System.out.println("Digite a sessão: ");
				String sessao = sc.nextLine().strip();
				usuario = new AssessorTecnico(nome, matricula, sessao);
			}
			default -> {
				System.out.println("Opção invalida.");
				return;
			}
		}
		usuarios.add(usuario);
		System.out.println("Usuario cadastrado com sucesso");
	}

	private void menuCadastrarItem() {
		Item item = null;

		System.out.println("Digite o titulo: ");
		String titulo = sc.nextLine().strip();

		System.out.println("Digite o autor: ");
		String autor = sc.nextLine().strip();

		System.out.println("Digite o ano de publicacao: ");
		int anoPublicacao;
		try {
			anoPublicacao = Integer.parseInt(sc.nextLine());
		} catch (NumberFormatException e) {
			System.out.println("Ano de publicação invalido.");
			return;
		}

		System.out.println("Digite a quantidade disponivel: ");
		int qtdDisponivel;
		try {
			qtdDisponivel = Integer.parseInt(sc.nextLine());
		} catch (Exception e) {
			System.out.println("Quantidade disponivel invalida.");
			return;
		}

		System.out.println("Qual o tipo de Item ?\n" +
				"1) Livro\n" +
				"2) Revista\n" +
				"3) CD\n");
		switch (tryParseInt(sc.nextLine())) {
			case 1 -> {
				System.out.println("Digite a editora: ");
				String editora = sc.nextLine().strip();

				System.out.println("Digite o ISBN: ");
				String isbn = sc.nextLine().strip();

				item = new Livro(titulo, autor, anoPublicacao, qtdDisponivel, editora, isbn);
			}
			case 2 -> {
				System.out.println("Digite o volume: ");
				int volume;
				try {
					volume = Integer.parseInt(sc.nextLine());
				} catch (NumberFormatException e) {
					System.out.println("Volume invalido.");
					return;
				}

				System.out.println("Digite o numero: ");
				int numero;
				try {
					numero = Integer.parseInt(sc.nextLine());
				} catch (Exception e) {
					System.out.println("Numero invalido.");
					return;
				}

				item = new Revista(titulo, autor, anoPublicacao, qtdDisponivel, volume, numero);
			}
			case 3 -> {
				System.out.println("Digite o volume: ");
				int volume;
				try {
					volume = Integer.parseInt(sc.nextLine());
				} catch (Exception e) {
					System.out.println("Volume invalido.");
					return;
				}

				System.out.println("Digite o numero: ");
				String gravadora = sc.nextLine().strip();

				item = new CD(titulo, autor, anoPublicacao, qtdDisponivel, volume, gravadora);
			}
			default -> {
				System.out.println("Opção invalida.");
				return;
			}
		}
		itens.add(item);
		System.out.println("Item cadastrado com sucesso");
	}

	private void menuPesquisarUsuario() {
		System.out.println("Digite o nome ou matricula do usuario para pesquisar: ");
		String pesquisa = sc.nextLine().strip();
		Usuario usuario = pesquisaUsuario(pesquisa);
		if (usuario == null) {
			System.out.println("Usuario não encontrado. Tente novamente");
			return;
		}

		for (;;) {
			System.out.println("Usuario " + usuario.getNome() + " selecionado.");
			System.out.println("Selecione a opção desejada: \n" +
					"0) Voltar\n" +
					"1) Realizar Emprestimo\n" +
					"2) Realizar Devolução\n" +
					"3) Listar itens emprestados");
			switch (tryParseInt(sc.nextLine())) {
				case 0:
					return;
				case 1:
					menuRealizarEmprestimo(usuario);
					break;
				case 2:
					menuRealizarDevolucao(usuario);
					break;
				case 3:
					listarItensEmprestados(usuario);
					break;
				default:
					System.out.println("Opção invalida.");
					break;
			}
		}
	}

	private void menuRealizarEmprestimo(Usuario usuario) {
		System.out.println("Digite o Titulo ou Autor do item: ");
		String string = sc.nextLine().strip();
		Item item = pesquisaItem(string);
		if (item == null) {
			System.out.println("Item não encontrado.");
			return;
		} else if (item.getQtdDisponivel() <= 0) {
			System.out.println("Item indisponível");
			return;
		}
		System.out.println("Digite a quantidade de dias que o item vai ser emprestado:");
		int diasEmprestado;
		try {
			diasEmprestado = Integer.parseInt(sc.nextLine());
		} catch (Exception e) {
			System.out.println("Quantidade de dias invalida.");
			return;
		}

		this.emprestimos.add(usuario.realizarEmprestimo(item, diasEmprestado));
	}

	private void menuRealizarDevolucao(Usuario usuario) {
		System.out.println("Digite o titulo ou autor do item a devolver: ");
		Item item = pesquisaItem(sc.nextLine());
		if (item == null) {
			System.out.println("Item não encontrado.");
			return;
		}
		double taxa = usuario.realizarDevolucao(item);
		if (taxa == -1) {
			System.out.println("O usuario " + usuario.getNome() + " não emprestou este item.");
			return;
		}
		System.out.println("A multa a ser paga é de: R$" + taxa);
	}

	/*
	 * 3. Busca por itens disponıveis: busca pelo nome do item,
	 * listando os dados do item como quantidade disponıvel, etc.
	 */
	private void menuPesquisarItem() {
		System.out.println("Digite o nome do item a pesquisar:");
		Item item = pesquisaItem(sc.nextLine());
		if (item == null) {
			System.out.println("Item não encontrado");
			return;
		}
		System.out.println("################################################################################");
		System.out.println("Dados do item:" +
				"\nTitulo: " + item.getTitulo() +
				"\nAutor: " + item.getAutor() +
				"\nAno: " + item.getAnoPublicacao() +
				"\nQuantidade disponivel: " + item.getQtdDisponivel());
		System.out.println("################################################################################");
	}

	private void menuDevolucoesAtrasadas() {
		int i = 0;
		for (Emprestimo emprestimo : emprestimos) {
			if (emprestimo.getDataDevolucaoPrevista().toEpochDay() < LocalDate.now().toEpochDay()) {
				i++;
				System.out.println(i + ") ############################################");
				System.out.println("Dados do item: " +
						"\nTitulo: " + emprestimo.getItem().getTitulo() +
						"\nAutor: " + emprestimo.getItem().getAutor() +
						"\nAno: " + emprestimo.getItem().getAnoPublicacao() +
						"\nQuantidade disponivel: " + emprestimo.getItem().getQtdDisponivel());
				System.out.println("Dados do usuário: " +
						"\nNome: " + emprestimo.getUsuario().getNome() +
						"\nMatricula: " + emprestimo.getUsuario().getMatricula());
				System.out.println("################################################################################");
			}
		}
		if (i == 0)
			System.out.println("Nenhum item foi encontrado");

	}

	private Usuario pesquisaUsuario(String string) {
		for (Usuario usuario : usuarios) {
			if (usuario.getNome().equalsIgnoreCase(string) || usuario.getMatricula().equalsIgnoreCase(string)) {
				return usuario;
			}
		}
		return null;
	}

	private Item pesquisaItem(String string) {
		for (Item item : itens) {
			if (item.getTitulo().equalsIgnoreCase(string) || item.getAutor().equalsIgnoreCase(string)) {
				return item;
			}
		}
		return null;
	}

	private void listarItensEmprestados(Usuario usuario) {
		int i = 0;
		System.out.println("################################################################################");
		for (Emprestimo emprestimo : usuario.getEmprestimos()) {
			System.out.println(i + " - " + emprestimo.getItem().getTitulo());
		}
		System.out.println("################################################################################");
	}
}
