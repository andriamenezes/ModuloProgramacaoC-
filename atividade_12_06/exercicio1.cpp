#include <iostream>
using namespace std;

void trocar(int *a, int *b){
    *a = *a + *b;  // a recebe a soma dos dois
    *b = *a - *b;  // b recebe o valor original de a
    *a = *a - *b;  // a recebe o valor original de b
}

int main(){
    int x = 10, y = 20; //declara a variavel 

    cout << "Antes:  x=" << x << " y=" << y << endl; //imprime os valores 
    trocar(&x, &y); //chama a função trocar
    cout << "Depois: x=" << x << " y=" << y << endl; //imprime o valor depois
    return 0;  //encerra o programa
}

//A função só usa o que já existe — os próprios ponteiros *a e *b: