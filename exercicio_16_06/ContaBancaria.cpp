#include <iostream>
#include <string>
using namespace std;

//Definição da classe
class ContaBancaria {
    private:                    // só acessível dentro da classe
        string titular;
        double saldo;

    public:                     // acessível de fora da classe
        // Construtor
        ContaBancaria(string nome, double saldoInicial){
            titular = nome;
            saldo   = saldoInicial;
        }

        // Getters
        string getTitular(){ return titular; }
        double getSaldo()  { return saldo;   }

        // Métodos
        void depositar(double valor){
            if(valor > 0){
                saldo += valor;
                cout << "Depósito de R$" << valor << " realizado!" << endl;
            }
        }

        void sacar(double valor){
            if(valor > saldo)
                cout << "Saldo insuficiente! Saldo atual: R$" << saldo << endl;
            else{
                saldo -= valor;
                cout << "Saque de R$" << valor << " realizado!" << endl;
            }
        }
};

// Seu código original (não precisou mudar nada aqui)
int main(){
    ContaBancaria conta("João Silva", 1000.0);

    cout << "Titular: " << conta.getTitular() << endl;
    cout << "Saldo: "   << conta.getSaldo()   << endl;

    // conta.saldo = 500.0; // ❌ erro: saldo é privado

    conta.depositar(500.0);
    conta.sacar(200.0);
    conta.sacar(2000.0);    // tentativa de saque inválido

    cout << "Saldo final: R$" << conta.getSaldo() << endl;
    return 0;
}