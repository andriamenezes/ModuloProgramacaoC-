#include <iostream>
#include <string>
using namespace std;

// ═══════════════════════════════
//     CLASSE PAI: Funcionario
// ═══════════════════════════════
class Funcionario {
protected:
    string nome;
    float  salario;

public:
    // Construtor
    Funcionario(string nome, float salario) {
        this->nome    = nome;
        this->salario = salario;
    }

    // Getters
    string getNome()   { return nome;   }
    float  getSalario(){ return salario; }

    // Metodo que sera sobrescrito pelo filho
    void mostrarSalario() {
        cout << "Funcionario: " << nome    << endl;
        cout << "Salario:     " << salario << endl;
    }
};

// ═══════════════════════════════
//     CLASSE FILHA: Gerente
// ═══════════════════════════════
class Gerente : public Funcionario {
private:
    float bonus;

public:
    // Construtor chama o pai
    Gerente(string nome, float salario) : Funcionario(nome, salario) {
        bonus = salario * 0.20;   // 20% de bonus
    }

    // Sobrescreve o metodo do pai
    void mostrarSalario() {
        cout << "Gerente:     " << nome           << endl;
        cout << "Salario:     " << salario         << endl;
        cout << "Bonus (20%): " << bonus           << endl;
        cout << "Total:       " << salario + bonus << endl;
    }
};

// ═══════════════════════════════
//             MAIN
// ═══════════════════════════════
int main() {

    Funcionario f("Carlos", 3000.0);
    cout << "=== Funcionario ===" << endl;
    f.mostrarSalario();

    cout << endl;

    Gerente g("Ana", 5000.0);
    cout << "=== Gerente ===" << endl;
    g.mostrarSalario();

    return 0;
}