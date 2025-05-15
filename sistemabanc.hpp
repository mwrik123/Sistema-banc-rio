//Requisitos:
//Utilize encapsulamento para os atributos das classes.
//Implemente verificações necessárias, como saldo insuficiente para saques e transferências.
//Utilize métodos getters (e setters se necessário) para acessar os atributos privados.
//Adicione comentários no código para explicar o funcionamento.

#include <iostream>
#include <string>
using namespace std;

//Classe Cliente:
//Crie uma classe Cliente que represente um cliente do banco.
class Cliente {
    private:
        //Atributos privados:
        //nome (string): nome do cliente.
        //cpf (string): CPF ou identificador único do cliente.
        string nome;
        string cpf;
    public:
        //Construtor:
        //Inicialize os atributos nome e cpf.
        Cliente (string n, string c);
        //padrao
        Cliente (){};

        //Métodos públicos:
        //Métodos getter para acessar o nome e o cpf.
        string getNome() const;
        string getCpf() const;


};

class ContaBancaria {
//Classe ContaBancaria:
//Crie uma classe ContaBancaria que represente uma conta bancária.
    private:
        //Atributos privados:
        //numero (int): número da conta.
        int nconta;
        //saldo (double): saldo da conta.
        double salconta;
        //titular (Cliente): objeto do tipo Cliente que é o titular da conta.
        Cliente cliente;
    public:
        //Construtor:
        //Inicialize o numero, o titular e, opcionalmente, o saldo (padrão zero).
        ContaBancaria (int x, Cliente c, double s = 0);
        //padrao
        ContaBancaria(){};

        //Métodos públicos:
        //int verifica(double saldo): método para verificar se há saldo na conta.
        int verifica(double s, double v);
        //void depositar(double valor): método para depositar um valor na conta.
        void depositar(double v);

        //void sacar(double valor): método para sacar um valor da conta (verifique se há saldo suficiente).
        void sacar(double v);
        //Sobrecarga do método transferir:
        //void transferir(double valor, ContaBancaria &destino): método para transferir um valor para outra conta (verifique se há saldo suficiente).
        void transferir(double v, ContaBancaria &d);

        //void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2): método para transferir o valor dividido igualmente entre duas contas
        // destino (verifique se há saldo suficiente).
        void transferir(double v, ContaBancaria &d1, ContaBancaria &d2);

        //void exibirSaldo(): exibe o saldo atual da conta.
        void exibirSaldo();
        //void exibirInformacoes(): exibe as informações do titular e da conta.
        void exibirInformacoes();
};
