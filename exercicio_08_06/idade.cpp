#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int idade;

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Sua idade e: " << idade << " anos" << endl;

    double pi = 3.14159;
    cout << setprecision(pi) << endl; // Exibe o valor de pi com 2 casas decimais
    cout << fixed << setprecision(2) << pi << endl;

    return 0;
}