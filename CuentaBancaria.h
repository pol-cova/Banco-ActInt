//
// Created by Paul Contreras on 26/02/24.
//

#ifndef BANCO_CUENTABANCARIA_H
#define BANCO_CUENTABANCARIA_H

#include <utility>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "EstadosCuenta.h"
using namespace std;

class CuentaBancaria {
public:
    CuentaBancaria(long int acc, float bal, string name){
        accountNumber = acc;
        balance = bal;
        userName = std::move(name);
    }
    // Getters
    string getAccount();
    string getName();
    string getSaldoFormat(float cant);
    float getSaldo();
    void getMovimientos();
    // Setters
    void setSaldo(float saldo);
    void realizarDeposito(float cant);
    void realizarRetiro(float cant);
    void actualizarEstado(const string& tipo, float cant);
private:
    // Var to store account number
    long int accountNumber;
    // Var to store account balance
    float balance;
    // List of transactions
    vector<EstadosCuenta>Movimientos;
    string userName;

};


#endif //BANCO_CUENTABANCARIA_H
