#include <iostream>
#include <string>
#include <windows.h> 

class Produto
{
private:
    std::string nome;
    double PrecoUnitario;
    int quantidade;

public:
    Produto() : nome("vazio"), PrecoUnitario(0.0), quantidade(0) {};

    void SetDados(int i)
    {
        std::cout << "Digite o nome do Produto " << (i + 1) << ": ";
        std::cin >> nome;

        std::cout << "Digite o Preco do Produto " << (i + 1) << ": ";
        std::cin >> PrecoUnitario;

        std::cout << "Digite a Quantidade do Produto " << (i + 1) << ": ";
        std::cin >> quantidade;

        std::cout << "\n\n\n";
    }

    double calcularTotal()
    {
        double total{ 0 };
        total = quantidade * PrecoUnitario;
        return total;
    }

    void Exibir(double total)
    {
        std::cout << "Nome: " << nome << "\n";
        std::cout << "precoUnidade: " << PrecoUnitario << "\n";
        std::cout << "ValorTotal: " << total << "\n\n\n";
    }
};

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    double ValorTotalLote{ 0 };
    int Qnt;

    std::cout << "Quantos produtos diferentes chegaram ao estoque: ";
    std::cin >> Qnt;

    std::cout << "\n\n\n";

    Produto* ptrLote = new Produto[Qnt];

    for (int i = 0; i < Qnt; i++)
    {
        (ptrLote + i)->SetDados(i);
        ValorTotalLote += (ptrLote + i)->calcularTotal();
    }

    for (int i = 0; i < Qnt; i++)
    {
        double totalDoProduto = (ptrLote + i)->calcularTotal();
        (ptrLote + i)->Exibir(totalDoProduto);
    }

    std::cout << "VALOR TOTAL DO LOTE: R$ " << ValorTotalLote << "\n";

    delete[] ptrLote;
    ptrLote = nullptr;

    return 0;
}