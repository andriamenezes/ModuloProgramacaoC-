#include <iostream>
#include <string>
using namespace std;

// ═══════════════════════════════
//       CLASSE PAI: Veiculo
// ═══════════════════════════════
class Veiculo {
protected:          // protected = filhos podem acessar!
    string marca;

public:
    // Construtor da classe pai
    Veiculo(string marca) {
        this->marca = marca;
    }

    // Getter
    string getMarca() { return marca; }

    // Exibir
    void exibir() {
        cout << "Marca: " << marca << endl;
    }
};

// ═══════════════════════════════
//     CLASSE FILHA: Carro
// ═══════════════════════════════
class Carro : public Veiculo {   // herda de Veiculo
private:
    string modelo;

public:
    // Construtor chama o pai com : Veiculo(marca)
    Carro(string marca, string modelo) : Veiculo(marca) {
        this->modelo = modelo;
    }

    // Getter
    string getModelo() { return modelo; }

    // Exibir (sobrescreve o do pai)
    void exibir() {
        cout << "Marca:  " << marca  << endl;
        cout << "Modelo: " << modelo << endl;
    }
};

// ═══════════════════════════════
//             MAIN
// ═══════════════════════════════
int main() {

    // Criando objeto da classe PAI
    Veiculo v("Honda");
    cout << "=== Veiculo ===" << endl;
    v.exibir();

    cout << endl;

    // Criando objeto da classe FILHA
    Carro c("Toyota", "Corolla");
    cout << "=== Carro ===" << endl;
    c.exibir();

    return 0;
}