#include <iostream>
#include <string>
using namespace std;

class Aluno {
private: //classes privadas
    string __nome;
    float __nota;

public: //publicas
    // Construtor
    Aluno(string nome, float nota) {
        __nome = nome;
        set_nota(nota);
    }

    // Setter com validação
    void set_nota(float nota) {
        if (nota >= 0 && nota <= 10) {
            __nota = nota;
        } else {
            cout << "Erro: nota deve ser entre 0 e 10!" << endl;
        }
    }

    // Getters
    float get_nota() { return __nota; }
    string get_nome() { return __nome; }
};

int main() {
    Aluno a("Carlos", 8.5);

    cout << "Nome: " << a.get_nome() << endl;
    cout << "Nota: " << a.get_nota() << endl;

    a.set_nota(12); // Deve mostrar mensagem de erro

    return 0;
}