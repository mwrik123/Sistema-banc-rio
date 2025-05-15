#include <iostream>
#include "sistemabanc.hpp"

using namespace std;

int main(){
    //declaração de variáveis
    string nome, cpf, opc;
    double saldo, valor;
    int c1, c2, c3;
    //declaração de array de clientes e de contas bancarias
    Cliente clientes[50];
    ContaBancaria contas[50];
    int c4 = 0;
    //inicio do codigo
    cout << "" << endl;
    cout << "Nome, CPF e saldo inicial dos clientes: " << endl;
    cout << "" << endl;
    //while para criar lista de clientes e de contas bancarias
    while(true){
        //decidir se adiciona nova conta ou nao
        cout << "Adicionar(Sim ou nao)? " << endl;
        cin >> nome;
        cin.ignore();
        if(nome == "sim" || nome == "Sim"){
            cout << "" << endl;
            cout << "Cliente " << c4+1 << ": " << endl;
            cout << "" << endl;
            cout << "Nome: " << endl;
            cin >> nome;
            cin.ignore();
            cout << "" << endl;
            cout << "CPF: " << endl;
            cin >> cpf;
            cin.ignore();
            cout << "" << endl;
            //opção para adicionar saldo ou nao
            cout << "Deseja adicionar saldo?(Sim ou nao)" << endl;
            cin >> opc;
            cin.ignore();
            if(opc == "sim" || opc == "Sim"){
                cout << "Saldo inicial: " << endl;
                cin >> saldo;
                cin.ignore();
                cout << "" << endl;
                clientes[c4] = Cliente(nome, cpf);
                contas[c4] = ContaBancaria(1001+c4, clientes[c4], saldo);
            } else {
                clientes[c4] = Cliente(nome, cpf);
                contas[c4] = ContaBancaria(1001+c4, clientes[c4]);
            }
        } else {
            //para o while
            cout << "" << endl;
            break;
        }
        c4++;
    }
    //painel de funções possiveis
    while(true){
        cout << "Escolha um numero: " << endl;
        cout << "" << endl;
        cout << "1. Exibir saldo de conta" << endl;
        cout << "2. Transferencia unica" << endl;
        cout << "3. Transferencia dupla" << endl;
        cout << "4. Exibir informacoes de conta" << endl;
        cout << "5. Deposito" << endl;
        cout << "6. Saque" << endl;
        cout << "7. Encerrar" << endl;
        cin >> c1;
        cin.ignore();
        cout << "" << endl;
        //exibe o saldo de uma conta pelo seu numero
        if(c1 == 1){
            cout << "Qual conta deseja verificar o saldo?(Digite o numero da conta ex.: 1001)" << endl;
            cin >> c2;
            cin.ignore();
            cout << "" << endl;
            contas[c2-1001].exibirSaldo();
            cout << "" << endl;
        }
        //metodo para transferencia unica 
        else if(c1 == 2){
            cout << "De qual conta deseja transferir o dinheiro?(Digite o numero da conta ex.: 1001)" << endl;
            cin >> c3;
            cin.ignore();
            cout << "" << endl;
            cout << "Qual o valor da transferencia?" << endl;
            cin >> valor;
            cin.ignore();
            cout << "" << endl;
            cout << "Para qual conta?(Digite o numero da conta ex.: 1001)" << endl;
            cin >> c2;
            cin.ignore();
            cout << "" << endl;
            contas[c3-1001].transferir(valor, contas[c2-1001]);
            contas[c2-1001].exibirSaldo();
            contas[c3-1001].exibirSaldo();
            cout << "" << endl;
        } 
        //metodo para transferencia dupla
        else if(c1 == 3){
            cout << "De qual conta deseja transferir o dinheiro?(Digite o numero da conta ex.: 1001)" << endl;
            cin >> c3;
            cin.ignore();
            cout << "" << endl;
            cout << "Qual o valor a ser dividido igualmente entre as duas contas?" << endl;
            cin >> valor;
            cin.ignore();
            cout << "" << endl;
            cout << "Conta 1(Digite o numero da conta ex.: 1001): " << endl;
            cin >> c2;
            cin.ignore();
            cout << "" << endl;
            cout << "Conta 2(Digite o numero da conta ex.: 1001): " << endl;
            cin >> c4;
            cin.ignore();
            cout << "" << endl;
            contas[c3-1001].transferir(valor, contas[c2-1001], contas[c4-1001]);
            contas[c3-1001].exibirSaldo();
            contas[c2-1001].exibirSaldo();
            contas[c4-1001].exibirSaldo();
            cout << "" << endl;
        } 
        //metodo para exibir informações
        else if(c1 == 4){
            cout << "Exibir informacoes de qual conta?(Digite o numero da conta a partir de ex.: 1001)" << endl;
            cin >> c2;
            cin.ignore();
            cout << "" << endl;
            contas[c2-1001].exibirInformacoes();
            cout << "" << endl;
        } 
        //metodo para depositar um valor na conta
        else if(c1 == 5){
            cout << "Em qual conta deseja depositar?(Digite o numero da conta ex.: 1001)" << endl;
            cin >> c2;
            cin.ignore();
            cout << "" << endl;
            cout << "Valor a depositar: " << endl;
            cin >> valor;
            cin.ignore();
            cout << "" << endl;
            contas[c2-1001].depositar(valor);
            cout << "" << endl;
            contas[c2-1001].exibirSaldo();
            cout << "" << endl;
        } 
        //metodo para sacar um valor da conta
        else if(c1 == 6){
            cout << "De qual conta deseja sacar?(Digite o numero da conta ex.: 1001)" << endl;
            cin >> c2;
            cin.ignore();
            cout << "" << endl;
            cout << "Valor a sacar: " << endl;
            cin >> valor;
            cin.ignore();
            cout << "" << endl;
            contas[c2-1001].sacar(valor);
            cout << "" << endl;
            contas[c2-1001].exibirSaldo();
            cout << "" << endl;
        } 
        //encerra o codigo
        else if(c1 == 7){
            break;
        }
    }
}