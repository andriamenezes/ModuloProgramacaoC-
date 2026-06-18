#include <iostream>
#include <string>
using namespace std;

// ═══════════════════════════════
//      CLASSE BASE: Produto
// ═══════════════════════════════
class Produto {
protected:
    string nome;
    float  preco;

public:
    // Construtor
    Produto(string nome, float preco) {
        this->nome  = nome;
        this->preco = preco;
    }

    // Getters
    string getNome()  { return nome;  }
    float  getPreco() { return preco; }

    // Exibir (sera sobrescrito pelos filhos)
    void exibir() {
        cout << "Nome:  " << nome  << endl;
        cout << "Preco: " << preco << endl;
    }
};

// ═══════════════════════════════
//     SUBCLASSE: Livro
// ═══════════════════════════════
class Livro : public Produto {
private:
    string autor;

public:
    // Construtor chama o pai
    Livro(string nome, float preco, string autor) : Produto(nome, preco) {
        this->autor = autor;
    }

    // Getter
    string getAutor() { return autor; }

    // Sobrescreve exibir
    void exibir() {
        cout << "Nome:  " << nome  << endl;
        cout << "Preco: " << preco << endl;
        cout << "Autor: " << autor << endl;
    }
};

// ═══════════════════════════════
//     SUBCLASSE: Eletronico
// ═══════════════════════════════
class Eletronico : public Produto {
private:
    string marca;

public:
    // Construtor chama o pai
    Eletronico(string nome, float preco, string marca) : Produto(nome, preco) {
        this->marca = marca;
    }

    // Getter
    string getMarca() { return marca; }

    // Sobrescreve exibir
    void exibir() {
        cout << "Nome:  " << nome  << endl;
        cout << "Preco: " << preco << endl;
        cout << "Marca: " << marca << endl;
    }
};

// ═══════════════════════════════
//             MAIN
// ═══════════════════════════════
int main() {

    // 2 objetos Livro
    Livro l1("Dom Casmurro",      29.90, "Machado de Assis");
    Livro l2("O Cortico",         24.90, "Alcantara Machado");

    cout << "===== LIVROS =====" << endl;
    cout << "\n[ Livro 1 ]" << endl;
    l1.exibir();
    cout << "\n[ Livro 2 ]" << endl;
    l2.exibir();

    // 2 objetos Eletronico
    Eletronico e1("Notebook",    3500.00, "Dell");
    Eletronico e2("Smartphone",  1800.00, "Samsung");

    cout << "\n===== ELETRONICOS =====" << endl;
    cout << "\n[ Eletronico 1 ]" << endl;
    e1.exibir();
    cout << "\n[ Eletronico 2 ]" << endl;
    e2.exibir();

    return 0;
}

//heranças servem para reaproveitar código, evitando repetição. A classe base (Produto) tem os atributos e métodos comuns, enquanto as subclasses (Livro e Eletronico) adicionam detalhes específicos. Assim, podemos criar diferentes tipos de produtos sem precisar reescrever o código básico.