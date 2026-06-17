#include <iostream>
#include <string>
using namespace std;

class Jogo {
public:
    int golsA;
    int golsB;

    Jogo() {
        golsA = 0;
        golsB = 0;
    }

    Jogo(int a, int b) {
        golsA = a;
        golsB = b;
    }
};

class Apostador {
private:
    Jogo* palpites;

public:
    string nome;
    int pontuacao;

    Apostador() {
        nome = "";
        pontuacao = 0;
        palpites = new Jogo[4];
    }

    ~Apostador() {
        delete[] palpites;
    }

    void registrarPalpites() {
        cout << "\nNome do apostador: ";
        cin.ignore();
        getline(cin, nome);

        for (int i = 0; i < 4; i++) {
            cout << "\nJogo " << i + 1 << endl;

            cout << "Gols Time A: ";
            cin >> palpites[i].golsA;

            cout << "Gols Time B: ";
            cin >> palpites[i].golsB;
        }
    }

    int calcularPontuacao(Jogo jogosOficiais[]) {
        pontuacao = 0;

        for (int i = 0; i < 4; i++) {

            // Placar exato
            if (palpites[i].golsA == jogosOficiais[i].golsA &&
                palpites[i].golsB == jogosOficiais[i].golsB) {
                pontuacao += 10;
            }

            // Vencedor correto
            else {
                int resultadoPalpite;
                int resultadoOficial;

                if (palpites[i].golsA > palpites[i].golsB)
                    resultadoPalpite = 1;
                else if (palpites[i].golsA < palpites[i].golsB)
                    resultadoPalpite = -1;
                else
                    resultadoPalpite = 0;

                if (jogosOficiais[i].golsA > jogosOficiais[i].golsB)
                    resultadoOficial = 1;
                else if (jogosOficiais[i].golsA < jogosOficiais[i].golsB)
                    resultadoOficial = -1;
                else
                    resultadoOficial = 0;

                if (resultadoPalpite == resultadoOficial)
                    pontuacao += 5;
            }

            // Diferença de gols correta
            int diferencaPalpite =
                palpites[i].golsA - palpites[i].golsB;

            int diferencaOficial =
                jogosOficiais[i].golsA - jogosOficiais[i].golsB;

            if (diferencaPalpite == diferencaOficial)
                pontuacao += 2;
        }

        return pontuacao;
    }
};

void ordenarRanking(Apostador apostadores[], int qtd) {

    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {

            if (apostadores[j].pontuacao >
                apostadores[i].pontuacao) {

                Apostador temp = apostadores[i];
                apostadores[i] = apostadores[j];
                apostadores[j] = temp;
            }
        }
    }
}

int main() {

    const int NUM_JOGOS = 4;
    const int NUM_APOSTADORES = 3;

    Jogo jogosOficiais[NUM_JOGOS];

    Apostador apostadores[NUM_APOSTADORES];

    int opcao;

    do {

        cout << "\n===== BOLAO COPA 2026 =====\n";
        cout << "1 - Registrar resultados oficiais\n";
        cout << "2 - Registrar apostas\n";
        cout << "3 - Calcular pontuacao e ranking\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {

        case 1:

            cout << "\nDigite os resultados oficiais:\n";

            for (int i = 0; i < NUM_JOGOS; i++) {

                cout << "\nJogo " << i + 1 << endl;

                cout << "Gols Time A: ";
                cin >> jogosOficiais[i].golsA;

                cout << "Gols Time B: ";
                cin >> jogosOficiais[i].golsB;
            }

            break;

        case 2:

            for (int i = 0; i < NUM_APOSTADORES; i++) {
                cout << "\n=== Apostador "
                     << i + 1 << " ===\n";

                apostadores[i].registrarPalpites();
            }

            break;

        case 3:

            for (int i = 0; i < NUM_APOSTADORES; i++) {
                apostadores[i].calcularPontuacao(jogosOficiais);
            }

            ordenarRanking(apostadores, NUM_APOSTADORES);

cout << "\n===== RANKING =====\n";

            for (int i = 0; i < NUM_APOSTADORES; i++) {

                cout << i + 1 << "º - "
                     << apostadores[i].nome
                     << " - "
                     << apostadores[i].pontuacao
                     << " pontos\n";
            }

            break;

        case 4:

            cout << "\nPrograma encerrado.\n";
            break;

        default:

            cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 4);

    return 0;
}