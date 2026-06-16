#include <iostream>
using namespace std;

int main(){

    short int * pi = new short int;
    *pi = 1001;
    cout << "Valor inteiro =" << *pi << endl;
    cout << "Localização =" << pi << endl << endl;

    float *pf = new float;
    *pf = 123.35f;
    cout << "(Float)Valor ponto-flutuante =" << *pf << endl;
    cout << "(Float)Localização =" << pf << endl << endl;

    double *pd = new double;
    *pd = 500.35;
    cout << "(Double8bytes)Valor ponto-flutuante =" << *pd << endl;
    cout << "(Double8bytes)Localização =" << pd << endl << endl;

    cout << "(Int4bytes)Tamanho de pi = "  << sizeof(pi)  << endl;
    cout << "(Int4bytes)Tamanho de *pi = " << sizeof(*pi) << endl;
    cout << "(Double8bytes)Tamanho de pd = "  << sizeof(pd)  << endl;
    cout << "(Double8bytes)Tamanho de *pd = " << sizeof(*pd) << endl;
    cout << "(float4bytes)Tamanho de pf = "  << sizeof(pf)  << endl;
    cout << "(float4bytes)Tamanho de *pf = " << sizeof(*pf) << endl;

    delete pi;
    delete pf;
    delete pd;

    return 0;
}