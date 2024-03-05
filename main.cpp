#include <iostream>
#include <string>

using namespace std;

class Conta {
protected:
    string titular;
    double saldo;
public:
    Conta(string nome, double saldo_inicial) : titular(nome), saldo(saldo_inicial) {}
    virtual ~Conta() {}

    virtual void sacar(double valor) {
        if (valor > saldo) {
            cout << "Erro: Saldo insuficiente." << endl;
        } else {
            saldo -= valor;
            cout << "Saque de $" << valor << " realizado com sucesso." << endl;
        }
    }

    double verificarSaldo() {
        return saldo;
    }
};

class ContaInvestimento : public Conta {
public:
    ContaInvestimento(string nome, double saldo_inicial) : Conta(nome, saldo_inicial) {}

    void sacar(double valor) override {
        cout << "Erro: Operação de saque não permitida em conta de investimento." << endl;
    }
};

class ContaPoupanca : public Conta {
public:
    ContaPoupanca(string nome, double saldo_inicial) : Conta(nome, saldo_inicial) {}

    void sacar(double valor) override {
        if (valor > saldo) {
            cout << "Erro: Saldo insuficiente." << endl;
        } else {
            saldo -= valor;
            cout << "Saque de $" << valor << " realizado com sucesso." << endl;
            cout << "Lembrete: Em uma conta poupança, é recomendado manter um saldo mínimo." << endl;
        }
    }
};

class ContaCorrente : public Conta {
public:
    ContaCorrente(string nome, double saldo_inicial) : Conta(nome, saldo_inicial) {}

    void sacar(double valor) override {
        if (valor > saldo) {
            cout << "Erro: Saldo insuficiente." << endl;
        } else {
            saldo -= valor;
            cout << "Saque de $" << valor << " realizado com sucesso." << endl;
        }
    }
};

int main() {
    ContaInvestimento investimento("Joao", 10000);
    ContaPoupanca poupanca("Maria", 5000);
    ContaCorrente corrente("Pedro", 3000);

    investimento.sacar(2000);
    cout << "Saldo da conta de investimento: $" << investimento.verificarSaldo() << endl;

    poupanca.sacar(7000);
    cout << "Saldo da conta poupança: $" << poupanca.verificarSaldo() << endl;

    corrente.sacar(4000);
    cout << "Saldo da conta corrente: $" << corrente.verificarSaldo() << endl;

    return 0;
}
