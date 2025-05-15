#include <iostream>
#include "sistemabanc.hpp"

using namespace std;
//Construtor:
//Inicialize os atributos nome e cpf.
Cliente :: Cliente(string n, string c) : 
    nome(n), cpf(c){};

//Métodos públicos:
//Métodos getter para acessar o nome e o cpf.
string Cliente :: getCpf() const{
    return cpf;
}
string Cliente ::  getNome() const{
    return nome;
}

//Construtor:
//Inicialize o numero, o titular e, opcionalmente, o saldo (padrão zero).
ContaBancaria :: ContaBancaria(int x, Cliente c, double s) :
nconta(x), salconta(s), cliente(c){}

//Métodos públicos:
//int verifica(double saldo): método para verificar se há saldo na conta.
int ContaBancaria :: verifica(double s, double v){
    if(s >= v){
        return 1;
    } else {
        return 0;
    }
}
//void depositar(double valor): método para depositar um valor na conta.
void ContaBancaria :: depositar(double v){
    salconta = salconta + v;
}
//void sacar(double valor): método para sacar um valor da conta (verifique se há saldo suficiente).
void ContaBancaria :: sacar(double v){
    if(verifica(salconta, v) == 1){
        salconta = salconta - v;
        cout << "Saque concluido!" << endl;
    } else {
        cout << "Saldo insuficiente!" << endl;
    }
}

//Sobrecarga do método transferir:
//void transferir(double valor, ContaBancaria &destino): método para transferir um valor para outra conta (verifique se há saldo suficiente).]
void ContaBancaria :: transferir(double v, ContaBancaria &destino){
    if(verifica(salconta, v) == 1){
        salconta = salconta - v;
        destino.salconta = destino.salconta + v;
    } else {
        cout << "Saldo insuficiente!" << endl;
    }
}

//void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2): método para transferir o valor dividido igualmente entre duas contas destino
//(verifique se há saldo suficiente).
void ContaBancaria :: transferir(double v, ContaBancaria &d1, ContaBancaria &d2){
    if(verifica(salconta, v) == 1){
        salconta = salconta - v;
        d1.salconta = d1.salconta + (v/2);
        d2.salconta = d2.salconta + (v/2);
    } else {
        cout << salconta << endl;
        cout << "Saldo insuficiente!" << endl;
    }
}

//void exibirSaldo(): exibe o saldo atual da conta.
void ContaBancaria :: exibirSaldo(){
    cout << "Saldo atual de " << cliente.getNome() << ": "<< salconta << endl;
}

//void exibirInformacoes(): exibe as informações do titular e da conta.
void ContaBancaria :: exibirInformacoes(){
    cout << "Numero da conta: " << nconta << endl;
    cout << "Titular: " << cliente.getNome() << endl;
    cout << "CPF: " << cliente.getCpf() << endl;
    cout << "Saldo: " << salconta << endl;
}