#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double nota1, nota2, media;

    cout << "Digite a nota 1: ";
    cin >> nota1;

    cout << "Digite a nota 2: ";
    cin >> nota2;

    media = (nota1 + nota2) / 2;

    cout << "Sua media e: " << fixed << setprecision(2) << media << endl;

    return 0;
}