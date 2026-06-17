#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Biblioteca {
private:
    string nome;
    vector<string> livros;

public:
    // Construtor
    Biblioteca(string nome) {
        this->nome = nome;
    }

    // Getter do nome
    string getNome() {
        return nome;
    }

    // Setter do nome (nao aceita vazio)
    void setNome(string novo_nome) {
        if (novo_nome != "") {
            nome = novo_nome;
            cout << "Nome alterado para: " << nome << endl;
        } else {
            cout << "Erro: nome nao pode ser vazio!" << endl;
        }
    }

    // Adiciona livro (sem duplicata e sem titulo vazio)
    void adicionarLivro(string titulo) {
        if (titulo == "") {
            cout << "Erro: titulo nao pode ser vazio!" << endl;
            return;
        }

        for (string l : livros) {
            if (l == titulo) {
                cout << "Livro '" << titulo << "' ja existe na lista!" << endl;
                return;
            }
        }

        livros.push_back(titulo);
        cout << "Livro '" << titulo << "' adicionado!" << endl;
    }

    // Lista todos os livros
    void listarLivros() {
        cout << "\n--- Livros da " << nome << " ---" << endl;
        if (livros.empty()) {
            cout << "Nenhum livro cadastrado." << endl;
        } else {
            for (string l : livros) {
                cout << "- " << l << endl;
            }
        }
    }
};

int main() {
    // Cria a biblioteca
    Biblioteca b("Biblioteca Central");

    // Adiciona 3 livros diferentes
    b.adicionarLivro("Dom Casmurro");
    b.adicionarLivro("O Cortico");
    b.adicionarLivro("Memorias Postumas");

    // Tenta adicionar livro repetido
    b.adicionarLivro("Dom Casmurro");

    // Lista os livros
    b.listarLivros();

    // Altera o nome e exibe
    cout << endl;
    b.setNome("Biblioteca Municipal");
    cout << "Novo nome: " << b.getNome() << endl;

    return 0;
}