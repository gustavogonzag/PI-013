#include <iostream>
#include <string>

using namespace std;

struct Empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};

void Reajusta_dez_porcento(Empregado empregados[], int numEmpregados) {
    for (int i = 0; i < numEmpregados; i++) {
        empregados[i].salario *= 1.10; // Aumento de 10%
    }
}

int main() {
    Empregado empregados[50];
    int numEmpregados;

    cout << "Digite o número de empregados (até 50): ";
    cin >> numEmpregados;

    if (numEmpregados < 1 || numEmpregados > 50) {
        cout << "Número de empregados inválido!" << endl;
        return 1;
    }

    for (int i = 0; i < numEmpregados; i++) {
        cout << "Empregado " << i + 1 << ":" << endl;
        cout << "Nome: ";
        cin >> empregados[i].nome;
        cout << "Sobrenome: ";
        cin >> empregados[i].sobrenome;
        cout << "Ano de Nascimento: ";
        cin >> empregados[i].anoNascimento;
        cout << "RG: ";
        cin >> empregados[i].RG;
        cout << "Ano de Admissão: ";
        cin >> empregados[i].anoAdmissao;
        cout << "Salário: ";
        cin >> empregados[i].salario;
    }

    Reajusta_dez_porcento(empregados, numEmpregados);

    cout << "\nSalários reajustados em 10%:" << endl;
    for (int i = 0; i < numEmpregados; i++) {
        cout << "Empregado " << i + 1 << ": " << empregados[i].nome << " " << empregados[i].sobrenome << " - Salário: " << empregados[i].salario << endl;
    }

    return 0;
}
