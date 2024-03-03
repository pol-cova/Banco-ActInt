//
// Created by Paul Contreras on 26/02/24.
//

#include "CuentaBancaria.h"


string CuentaBancaria::getAccount() {
    string account = to_string(accountNumber);
    return account;
}

float CuentaBancaria::getSaldo() {
    return balance;
}

void CuentaBancaria::getMovimientos() {
    // Print header for "Estado de cuenta"
    cout << setfill('-') << setw(60) << "" << endl;
    cout << "|            Resumen de movimientos           |" << endl;
    cout << setfill('-') << setw(60) << "" << endl;
    cout<<"Cliente: "<<userName<<endl;
    cout<<"Numero Cuenta: "<<accountNumber<<endl;
    cout << setfill('=') << setw(80) << "" << endl;
    cout << left << setw(30) << setfill(' ') << "Fecha";
    cout << left << setw(20) << setfill(' ') << "Movimiento";
    cout << left << setw(30) << setfill(' ') << "Cantidad";
    cout << setfill('=') << setw(80) << "" << endl;
    cout << setfill(' '); // Reset fill character to default space

    if (!Movimientos.empty()) {
        for (auto &Movimiento : Movimientos) {
            cout << left << setw(30) << Movimiento.getFechaMovimiento();
            cout << left << setw(20) << Movimiento.getTipoMovimiento();
            cout << left << setw(30) << Movimiento.getCantidadMovimientoFormat(Movimiento.getCantidadMovimiento());
            cout << endl;
        }
    }

}


void CuentaBancaria::setSaldo(float saldo) {
    balance = saldo;
}

void CuentaBancaria::realizarDeposito(float cant) {
    actualizarEstado("Deposito", cant);
    balance += cant;
}

void CuentaBancaria::realizarRetiro(float cant) {
    actualizarEstado("Retiro", cant);
    balance -= cant;
}

void CuentaBancaria::actualizarEstado(const string& tipo, float cant) {
    Movimientos.emplace_back(tipo, cant);
}

string CuentaBancaria::getName() {
    return userName;
}

string CuentaBancaria::getSaldoFormat(float cant) {
    ostringstream oss;
    oss << fixed << setprecision(2) << cant;
    string formatted = oss.str(); // Corrected: use oss.str() instead of oss.str
    // Find position of decimal point
    size_t pos = formatted.find('.');
    if (pos != std::string::npos) {
        // Insert commas for thousands separator
        for (int i = pos - 3; i > 0; i -= 3) {
            formatted.insert(i, ",");
        }
        // Append ".00" if necessary
        if (formatted.length() - pos < 3) {
            formatted.append(3 - (formatted.length() - pos), '0');
        }
    }
    return "$" + formatted;
}

