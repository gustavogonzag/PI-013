#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// Definição da estrutura de dados para produtos
struct Produto {
    string codigo;
    string nome;
    double preco;
};

// Função para verificar se um produto já existe no vetor
bool produtoExiste(const vector<Produto>& produtos, const string& codigo, const string& nome) {
    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo || produto.nome == nome) {
            return true;
        }
    }
    return false;
}

// Função para inserir um novo produto no vetor
void inserirProduto(vector<Produto>& produtos) {
    Produto novoProduto;
    cout << "Digite o código do produto (13 caracteres numéricos): ";
    cin >> novoProduto.codigo;
    cout << "Digite o nome do produto (até 20 caracteres): ";
    cin.ignore();
    getline(cin, novoProduto.nome);
    cout << "Digite o preço do produto: ";
    cin >> novoProduto.preco;

    if (novoProduto.codigo.length() != 13 || novoProduto.nome.length() > 20 || novoProduto.preco < 0.0) {
        cout << "Dados do produto inválidos. Verifique o código, nome e preço." << endl;
        return;
    }

    if (produtoExiste(produtos, novoProduto.codigo, novoProduto.nome)) {
        cout << "Produto com código ou nome já existe. Não é possível cadastrá-lo novamente." << endl;
    } else {
        produtos.push_back(novoProduto);
        cout << "Produto cadastrado com sucesso!" << endl;
    }
}

// Função para excluir um produto do vetor
void excluirProduto(vector<Produto>& produtos) {
    string codigoExcluir;
    cout << "Digite o código do produto a ser excluído: ";
    cin >> codigoExcluir;

    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->codigo == codigoExcluir) {
            it = produtos.erase(it);
            cout << "Produto excluído com sucesso!" << endl;
            return;
        }
    }

    cout << "Produto não encontrado. Verifique o código." << endl;
}

// Função para listar todos os produtos
void listarProdutos(const vector<Produto>& produtos) {
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado." << endl;
        return;
    }

    cout << "Lista de produtos cadastrados:" << endl;
    cout << left << setw(15) << "Código" << setw(25) << "Nome" << setw(15) << "Preço" << endl;
    cout << setfill('-') << setw(55) << "" << setfill(' ') << endl;

    for (const Produto& produto : produtos) {
        cout << setw(15) << produto.codigo << setw(25) << produto.nome << setw(15) << fixed << setprecision(2) << produto.preco << endl;
    }
}

// Função para consultar o preço de um produto por código
void consultarPreco(const vector<Produto>& produtos) {
    string codigoConsultar;
    cout << "Digite o código do produto para consultar o preço: ";
    cin >> codigoConsultar;

    for (const Produto& produto : produtos) {
        if (produto.codigo == codigoConsultar) {
            cout << "Preço do produto '" << produto.nome << "': R$" << fixed << setprecision(2) << produto.preco << endl;
            return;
        }
    }

    cout << "Produto não encontrado. Verifique o código." << endl;
}

int main() {
    vector<Produto> produtos;
    char opcao;

    while (true) {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Inserir novo produto" << endl;
        cout << "2. Excluir produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar preço de um produto" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case '1':
                inserirProduto(produtos);
                break;
            case '2':
                excluirProduto(produtos);
                break;
            case '3':
                listarProdutos(produtos);
                break;
            case '4':
                consultarPreco(produtos);
                break;
            case '5':
                cout << "Encerrando o programa. Obrigado!" << endl;
                return 0;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}
