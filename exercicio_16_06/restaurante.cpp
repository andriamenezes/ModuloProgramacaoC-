#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Restaurante {
private:
   string nome;
   vector<string> cardapio;

public:
   // Construtor
   Restaurante(string nome) {
       this->nome = nome;
   }

   // Getter do nome
   string getNome() {
       return nome;
   }

   // Setter do nome (só aceita string não vazia)
   void setNome(string novo_nome) {
       if (novo_nome != "") {
           nome = novo_nome;
       } else {
           cout << "Erro: nome não pode ser vazio!" << endl;
       }
   }

   // Adiciona prato se ainda não existir
   void adicionarPrato(string prato) {
       for (string p : cardapio) {
           if (p == prato) {
               cout << "Prato '" << prato << "' já existe no cardápio!" << endl;
               return;
           }
       }
       cardapio.push_back(prato);
       cout << "Prato '" << prato << "' adicionado!" << endl;
   }

   // Lista todos os pratos
   void listarCardapio() {
       cout << "\n--- Cardápio de " << nome << " ---" << endl;
       for (string p : cardapio) {
           cout << "- " << p << endl;
       }
   }

   // Atende cliente
   void atenderCliente(string nome_cliente, string prato) {
       for (string p : cardapio) {
           if (p == prato) {
               cout << nome_cliente << ", seu pedido de '" << prato << "' foi confirmado!" << endl;
               return;
           }
       }
       cout << "Desculpe " << nome_cliente << ", o prato '" << prato << "' não existe no cardápio." << endl;
   }
};

int main() {
   Restaurante r("Sabor Caseiro");

   // Adiciona 3 pratos
   r.adicionarPrato("Frango Grelhado");
   r.adicionarPrato("Arroz com Feijao");
   r.adicionarPrato("Peixe Assado");

   // Lista cardápio
   r.listarCardapio();

   // 2 clientes fazendo pedidos (um com prato inexistente)
   cout << endl;
   r.atenderCliente("Maria", "Frango Grelhado");
   r.atenderCliente("Joao", "Pizza");

   // Altera o nome e exibe
   cout << endl;
   r.setNome("Sabor da Vovó");
   cout << "Novo nome: " << r.getNome() << endl;

   return 0;
}