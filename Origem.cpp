#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

struct Livro
{
	int ID;
	std::string Titulo;
	std::string Editora;
	int ano;

public:

	Livro() : ID(0), Titulo("vazio"), Editora("vazio"), ano(0) {};

};

void SalvarArquivo(struct Livro* ponteiro)
{

	std:: ofstream arquivo("Livros.txt", std:: ios::app);

	arquivo << "Título: " << ponteiro->Titulo << "\n" << "Editora: " << ponteiro->Editora << "\n" << "ID: " << ponteiro->ID << "\n" <<"Ano de Lançamento: " << ponteiro->ano << "\n\n";

	arquivo.close();

}

int main()
{

	int escolha{ 0 };

	int indice{ 0 };

	int quantidade{ 10 };

	Livro* novo = new Livro[quantidade];

	while (1)
	{
		SetConsoleOutputCP(CP_UTF8);

		std::cout << "1 - Cadastrar Livro\n2 - Listar\n3 - Sair\nEscolha:";
		std::cin >> escolha;

		if (indice == quantidade)
		{
			int NovaQuantidade = quantidade + 10;
			Livro* temp = new Livro[NovaQuantidade];

			for (int i = 0; i < indice;i++)
			{
				temp[i] = novo[i];

			}
			delete[] novo;
			novo = temp;
			quantidade = NovaQuantidade;
		}

		if (escolha == 3)
		{
			exit(0);
		}

		if (escolha == 1)
		{
			std::cin.ignore();


			std::cout << "Digite o Título do Livro a ser adicionado:";
			std:: getline (std::cin, novo[indice].Titulo);

			std::cout << "Digite a Editora do Livro a ser adicionado:";
			std::getline(std::cin, novo[indice].Editora);

			std::cout << "Digite o ID do Livro a ser adicionado:";
			std::cin >> novo[indice].ID;

			std::cout << "Digite o ano de lançamento do Livro a ser adicionado:";
			std::cin >> novo[indice].ano;

			std::cout << "\nLivro Adicionado com sucesso!\n\n";

			SalvarArquivo(&novo[indice]);


			indice++;
		}
		if (escolha == 2)
		{
			for (int i = 0; i < indice; i++)
			{
				std::cout << "\nLivro " << i + 1 << "\n";

				std::cout << "nome :" << novo[i].Titulo << "\n";
				std::cout << "Editora:" << novo[i].Editora << "\n";
				std::cout << "id: " << novo[i].ID << "\n";
				std::cout << "Ano de Lançamento: " << novo[i].ano << "\n";

				std::cout << " \n\n";

			}
		}
	}

	delete[] novo;
	novo = nullptr;


	return 0;
}