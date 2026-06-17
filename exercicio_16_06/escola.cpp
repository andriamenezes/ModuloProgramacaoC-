#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ═══════════════════════════════
//         CLASSE ALUNO
// ═══════════════════════════════
class Aluno {
private:
    string nome;
    int    idade;
    string curso;

public:
    // Construtor
    Aluno(string nome, int idade, string curso) {
        setNome(nome);
        setIdade(idade);
        setCurso(curso);
    }

    // Getters
    string getNome()  { return nome;  }
    int    getIdade() { return idade; }
    string getCurso() { return curso; }

    // Setter nome (nao aceita vazio)
    void setNome(string novo_nome) {
        if (novo_nome != "") {
            nome = novo_nome;
        } else {
            cout << "Erro: nome nao pode ser vazio!" << endl;
        }
    }

    // Setter idade (apenas maior que 0)
    void setIdade(int nova_idade) {
        if (nova_idade > 0) {
            idade = nova_idade;
        } else {
            cout << "Erro: idade deve ser maior que 0!" << endl;
        }
    }

    // Setter curso (nao aceita vazio)
    void setCurso(string novo_curso) {
        if (novo_curso != "") {
            curso = novo_curso;
        } else {
            cout << "Erro: curso nao pode ser vazio!" << endl;
        }
    }

    // Apresentar aluno
    void apresentar() {
        cout << "Nome: " << nome
             << " | Idade: " << idade
             << " | Curso: " << curso << endl;
    }
};

// ═══════════════════════════════
//         CLASSE ESCOLA
// ═══════════════════════════════
class Escola {
private:
    string        nome;
    vector<Aluno> alunos;

public:
    // Construtor
    Escola(string nome) {
        this->nome = nome;
    }

    // Getter nome
    string getNome() { return nome; }

    // Setter nome (nao aceita vazio)
    void setNome(string novo_nome) {
        if (novo_nome != "") {
            nome = novo_nome;
        } else {
            cout << "Erro: nome da escola nao pode ser vazio!" << endl;
        }
    }

    // Adiciona aluno na lista
    void adicionarAluno(Aluno aluno) {
        alunos.push_back(aluno);
        cout << "Aluno '" << aluno.getNome() << "' matriculado!" << endl;
    }

    // Lista todos os alunos
    void listarAlunos() {
        cout << "\n--- Alunos da " << nome << " ---" << endl;
        if (alunos.empty()) {
            cout << "Nenhum aluno matriculado." << endl;
        } else {
            for (Aluno a : alunos) {
                a.apresentar();
            }
        }
    }
};

// ═══════════════════════════════
//             MAIN
// ═══════════════════════════════
int main() {

    // Cria a escola
    Escola escola("Escola Futuro");

    // Cria 2 alunos
    Aluno a1("Joao",  20, "Informatica");
    Aluno a2("Maria", 18, "Administracao");

    // Adiciona os alunos
    escola.adicionarAluno(a1);
    escola.adicionarAluno(a2);

    // Lista os alunos
    escola.listarAlunos();

    // Testa os setters
    cout << "\n--- Testando alteracoes ---" << endl;
    a1.setNome("Joao Silva");
    a1.setIdade(21);
    a1.setCurso("Redes");
    a1.apresentar();

    // Testa valores invalidos
    cout << "\n--- Testando valores invalidos ---" << endl;
    a2.setNome("");
    a2.setIdade(-5);
    a2.setCurso("");

    // Altera nome da escola
    cout << "\n--- Alterando nome da escola ---" << endl;
    escola.setNome("Escola do Futuro");
    cout << "Novo nome: " << escola.getNome() << endl;

    return 0;
}