#include <iostream>
#include <string>
using namespace std;

class Carro {
private:
    string marca;
    float velocidade;

public:
    // Construtor
    Carro(string marca, float velocidade) {
        this->marca = marca;
        this->velocidade = velocidade;
    }

    // Getters
    string getMarca()      { return marca;      }
    float  getVelocidade() { return velocidade; }

    // Acelerar
    void acelerar(float valor) {
        if (valor > 0) {
            velocidade += valor;
            cout << "Acelerando! Velocidade atual: " << velocidade << " km/h" << endl;
        } else {
            cout << "Erro: valor de aceleracao deve ser positivo!" << endl;
        }
    }

    // Frear (nunca abaixo de zero)
    void frear(float valor) {
        if (valor > 0) {
            velocidade -= valor;
            if (velocidade < 0) {
                velocidade = 0;   // nunca fica negativo!
            }
            cout << "Freando! Velocidade atual: " << velocidade << " km/h" << endl;
        } else {
            cout << "Erro: valor de frenagem deve ser positivo!" << endl;
        }
    }

    // Exibir dados
    void exibir() {
        cout << "Marca: "      << marca      << endl;
        cout << "Velocidade: " << velocidade << " km/h" << endl;
    }
};

int main() {
    Carro c1("Toyota", 0);

    cout << "=== Informacoes do Carro ===" << endl;
    c1.exibir();

    cout << "\n=== Acelerando ===" << endl;
    c1.acelerar(50);
    c1.acelerar(30);

    cout << "\n=== Freando ===" << endl;
    c1.frear(20);
    c1.frear(200);   // tenta passar do zero

    cout << "\n=== Estado Final ===" << endl;
    c1.exibir();

    return 0;
}