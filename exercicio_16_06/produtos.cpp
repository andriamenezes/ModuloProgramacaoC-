#include <iostream>
#include <string>
using namespace std;

class Produto {
private:
   string nome;
   float preco;

public:
   // Construtor
   Produto(string nome, float preco) {
       this->nome = nome;
       set_preco(preco);
   }

   // Setter com validação
   void set_preco(float preco) {
       if (preco > 0) {
           this->preco = preco;
       } else {
           cout << "Erro: preço não pode ser zero ou negativo!" << endl;
       }
   }

   // Getters
   string get_nome() { return nome; }
   float get_preco() { return preco; }

   // Exibir dados
   void exibir() {
       cout << "Produto: " << nome << " | Preço: R$ " << preco << endl;
   }
};

int main() {
   Produto p1("Caderno", 15.90);
   Produto p2("Mochila", 89.99);

   p1.exibir();
   p2.exibir();

   // Teste com preço inválido
   p1.set_preco(-5);  // Deve mostrar erro
   p2.set_preco(0);   // Deve mostrar erro

   return 0;
}