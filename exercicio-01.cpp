#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct Passagem {
    int numeroAssento;
    string dataHora;
    string CPF;
    string nome;
    int idade;
    double valor;
};

struct Viagem {
    int numeroViagem;
    string origem;
    string destino;
    string data;
    vector<Passagem> passagens;
};

vector<Viagem> viagens;

void registrarPassagem() {
    int numeroViagem;
    cout << "Digite o número da viagem (1-5): ";
    cin >> numeroViagem;

    if (numeroViagem < 1 || numeroViagem > 5) {
        cout << "Número de viagem inválido!" << endl;
        return;
    }

    Viagem& viagem = viagens[numeroViagem - 1];
    if (viagem.passagens.size() >= 40) {
        cout << "Ônibus lotado para esta viagem!" << endl;
        return;
    }

    Passagem passagem;
    passagem.numeroAssento = viagem.passagens.size() + 1;
    passagem.valor = 80.0;

    cout << "Digite a data e hora (dd/mm/aaaa hh:mm): ";
    cin >> passagem.dataHora;

    cout << "Digite o CPF: ";
    cin >> passagem.CPF;

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, passagem.nome);

    cout << "Digite a idade: ";
    cin >> passagem.idade;

    viagem.passagens.push_back(passagem);
    cout << "Passagem registrada com sucesso!" << endl;
}

double calcularTotalArrecadado(int numeroViagem) {
    double total = 0.0;
    const Viagem& viagem = viagens[numeroViagem - 1];

    for (const Passagem& passagem : viagem.passagens) {
        total += passagem.valor;
    }

    return total;
}

double calcularTotalArrecadadoNoMes(int mes) {
    double total = 0.0;

    for (const Viagem& viagem : viagens) {
        string data = viagem.data;
        int mesViagem = stoi(data.substr(3, 2));
        if (mesViagem == mes) {
            total += calcularTotalArrecadado(viagem.numeroViagem);
        }
    }

    return total;
}

string obterNomePassageiro(int numeroViagem, int numeroAssento) {
    const Viagem& viagem = viagens[numeroViagem - 1];

    for (const Passagem& passagem : viagem.passagens) {
        if (passagem.numeroAssento == numeroAssento) {
            return passagem.nome;
        }
    }

    return "Assento não encontrado";
}

string encontrarViagemMaisRentavel() {
    double maxArrecadacao = 0.0;
    string horarioMaisRentavel;

    for (const Viagem& viagem : viagens) {
        double arrecadacao = calcularTotalArrecadado(viagem.numeroViagem);
        if (arrecadacao > maxArrecadacao) {
            maxArrecadacao = arrecadacao;
            horarioMaisRentavel = viagem.data;
        }
    }

    return horarioMaisRentavel;
}

double calcularMediaIdadePassageiros() {
    double somaIdade = 0.0;
    int totalPassageiros = 0;

    for (const Viagem& viagem : viagens) {
        for (const Passagem& passagem : viagem.passagens) {
            somaIdade += passagem.idade;
            totalPassageiros++;
        }
    }

    if (totalPassageiros == 0) {
        return 0.0;
    }

    return somaIdade / totalPassageiros;
}

int main() {
    for (int i = 0; i < 5; i++) {
        Viagem viagem;
        viagem.numeroViagem = i + 1;
        viagem.origem = "Rio de Janeiro";
        viagem.destino = "São Paulo";
        viagem.data = "01/09/2023";
        viagens.push_back(viagem);
    }

    int opcao;
    while (true) {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Registrar Passagem" << endl;
        cout << "2. Calcular Total Arrecadado para uma Viagem" << endl;
        cout << "3. Calcular Total Arrecadado em um Mês" << endl;
        cout << "4. Obter Nome do Passageiro de um Assento" << endl;
        cout << "5. Encontrar Viagem Mais Rentável" << endl;
        cout << "6. Calcular Média de Idade dos Passageiros" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                registrarPassagem();
                break;
            case 2:
                int numViagem;
                cout << "Digite o número da viagem (1-5): ";
                cin >> numViagem;
                cout << "Total arrecadado: R$ " << calcularTotalArrecadado(numViagem) << endl;
                break;
            case 3:
                int mes;
                cout << "Digite o mês (1-12): ";
                cin >> mes;
                cout << "Total arrecadado no mês: R$ " << calcularTotalArrecadadoNoMes(mes) << endl;
                break;
            case 4:
                int numViagemAssento, numAssento;
                cout << "Digite o número da viagem (1-5): ";
                cin >> numViagemAssento;
                cout << "Digite o número do assento: ";
                cin >> numAssento;
                cout << "Nome do passageiro: " << obterNomePassageiro(numViagemAssento, numAssento) << endl;
                break;
            case 5:
                cout << "Horário da viagem mais rentável: " << encontrarViagemMaisRentavel() << endl;
                break;
            case 6:
                cout << "Média de idade dos passageiros: " << calcularMediaIdadePassageiros() << " anos" << endl;
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                return 0;
            default:
                cout << "Opção inválida!" << endl;
        }
    }

    return 0;
}
