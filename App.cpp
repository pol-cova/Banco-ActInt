//
// Created by Paul Contreras on 26/02/24.
//

#include "App.h"

void App::Run() {
    bool app = true;
    int userOption;
    vector<CuentaBancaria> cuentas;
    string nm;
    do {
        srand(static_cast<unsigned int>(time(nullptr)));
        long int accNumber = rand();
        header();
        menu();
        cout << "Selecciona una opcion: " << endl;
        cin >> userOption;
        if (cin.fail()){
            cout << "Ingresaste un caracter invalido, por favor ingresa un numero valido!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (userOption) {
            case 1:
                if(!cuentas.empty()){
                    bool userSection = true;
                    int acc;
                    int option;
                    float cant;
                    cout << setfill('-') << setw(40) << "" << endl;
                    cout << "|        Ingrese el numero de cuenta:    |" << endl;
                    cout << setfill('-') << setw(40) << "" << endl;
                    cin >> acc;

                    for (auto & cuenta : cuentas){
                        if(cuenta.getAccount() == to_string(acc)){

                            cout << setfill('-') << setw(40) << "" << endl;
                            cout << "|       Titular:  "<< cuenta.getName() <<" |" << endl;
                            cout << setfill('-') << setw(40) << "" << endl;
                            cout << setfill('-') << setw(40) << "" << endl;
                            cout << "|       Saldo actual:  "<< cuenta.getSaldo() <<" |" << endl;
                            cout << setfill('-') << setw(40) << "" << endl;
                            do {
                                menuCuenta(acc);
                                cout << "Seleccione una opcion: ";
                                cin>>option;
                                switch (option) {
                                    case 1:
                                        cout << "-------Retiro------" << endl;
                                        cout << "Ingrese cantidad a retirar (monto maximo: " << cuenta.getSaldo() << ") : ";
                                        cin >> cant;
                                        if(cuenta.getSaldo() > 0){
                                            if (cant <= cuenta.getSaldo()){
                                                cuenta.realizarRetiro(cant);
                                                cout << "Nuevo saldo: " << cuenta.getSaldo() << endl;
                                            }else{
                                                cout << "Saldo insuficiente, ingrese una cantidad menor!" << endl;
                                            }
                                        } else{
                                            cout << "Error en la operacion!" << endl;
                                            cout << "Tu cuenta esta vacia, deposita dinero ahora!" << endl;
                                        }
                                        break;
                                    case 2:
                                        cout << "-------Deposito------" << endl;
                                        cout << "Ingrese cantidad a depositar : ";
                                        cin >> cant;
                                        if (cant >= 0) {
                                            cuenta.realizarDeposito(cant);
                                            cout << "Nuevo saldo: " << cuenta.getSaldo() << endl;
                                        } else{
                                            cout << "Error en la operacion!" << endl;
                                            cout << "Ingresaste una cantidad negativa intente de nuevo!" << endl;
                                        }
                                        break;
                                    case 3:
                                        cuenta.getMovimientos();
                                        break;
                                    case 4:
                                        userSection = false;
                                        break;
                                    default:
                                        cout << "Ingrese una opcion valida!";
                                }
                            } while (userSection);
                        } else {
                            cout << "Error, no hay cuentas asociadas a ese numero, crea una ahora!" << endl;
                        }
                    }
                } else {
                    cout << "Aun, no hay cuentas creadas, crea una ahora!" << endl;
                }
                break;
            case 2:
                menuCrear();
                float initialBalance;
                cout << "Ingrese su nombre: ";
                getline(cin>>ws,nm);
                cout << "Ingresa el saldo inicial de apertura: ";
                cin >> initialBalance;
                if (!cuentas.empty()){
                    for (auto & cuenta: cuentas) {
                        if (cuenta.getAccount() == to_string(accNumber)){
                            cout << "Ya existe una cuenta asociada a ese numero!" << endl;
                            cout << "Cuenta: " << accNumber;
                        }else{
                            cuentas.emplace_back(CuentaBancaria(accNumber, initialBalance, nm));
                            cout << "Cuenta creada con exito!" << endl;
                            cout << "Numero de cuenta asociado: " << accNumber;
                        }
                    }
                } else{
                    cuentas.emplace_back(CuentaBancaria(accNumber, initialBalance, nm));
                    cout << "Cuenta creada con exito!" << endl;
                    cout << "Numero de cuenta asociado: " << accNumber;
                }
                cout << endl;
                break;
            case 3:
                if(!cuentas.empty()){
                    int acc;
                    float cant;

                    cout << setfill('-') << setw(40) << "" << endl;
                    cout << "|        Ingrese el numero de cuenta:    |" << endl;
                    cout << setfill('-') << setw(40) << "" << endl;
                    cin >> acc;

                    for (auto & cuenta : cuentas){
                        if(cuenta.getAccount() == to_string(acc)){
                            cout << "-------Deposito------" << endl;
                            cout << "Ingrese cantidad a depositar : ";
                            cin >> cant;
                            if (cant >= 0) {
                                cuenta.realizarDeposito(cant);
                                cout << "Nuevo saldo: " << cuenta.getSaldo() << endl;
                            } else{
                                cout << "Error en la operacion!" << endl;
                                cout << "Ingresaste una cantidad negativa intente de nuevo!" << endl;
                            }
                        } else {
                            cout << "Error, no hay cuentas asociadas a ese numero, crea una ahora!" << endl;
                        }
                    }
                } else {
                    cout << "Aun, no hay cuentas creadas, crea una ahora!" << endl;
                }
                break;
            case 4:
                if(!cuentas.empty()){
                    int acc;
                    float cant;

                    cout << setfill('-') << setw(40) << "" << endl;
                    cout << "|        Ingrese el numero de cuenta:    |" << endl;
                    cout << setfill('-') << setw(40) << "" << endl;
                    cin >> acc;

                    for (auto & cuenta : cuentas){
                        if(cuenta.getAccount() == to_string(acc)){
                            cout << "-------Retiro------" << endl;
                            cout << "Ingrese cantidad a retirar (monto maximo: " << cuenta.getSaldo() << ") : ";
                            cin >> cant;
                            if(cuenta.getSaldo() > 0){
                                if (cant <= cuenta.getSaldo()){
                                    cuenta.realizarRetiro(cant);
                                    cout << "Nuevo saldo: " << cuenta.getSaldo() << endl;
                                }else{
                                    cout << "Saldo insuficiente, ingrese una cantidad menor!" << endl;
                                }
                            } else{
                                cout << "Error en la operacion!" << endl;
                                cout << "Tu cuenta esta vacia, deposita dinero ahora!" << endl;
                            }
                        } else {
                            cout << "Error, no hay cuentas asociadas a ese numero, crea una ahora!" << endl;
                        }
                    }
                } else {
                    cout << "Aun, no hay cuentas creadas, crea una ahora!" << endl;
                }
                break;
            case 5:
                cout << setfill('=') << setw(40) << "" << endl;
                cout << "|        Cuentas                      |" << endl;
                cout << setfill('=') << setw(40) << "" << endl;
                if(!cuentas.empty()){
                    cout << left << setw(20) << setfill(' ') << "Titular";
                    cout << left << setw(30) << setfill(' ') << "Numero de cuenta";
                    cout << left << setw(20) << setfill(' ') << "Saldo";
                    cout << endl;
                    for (auto & cuenta : cuentas){
                        cout << left << setw(20) << setfill(' ') << cuenta.getName();
                        cout << left << setw(30) << setfill(' ') << cuenta.getAccount();
                        cout << left << setw(20) << setfill(' ') << cuenta.getSaldoFormat(cuenta.getSaldo());
                        cout << endl;
                    }
                } else{
                    cout << "No hay cuentas aun!, cree una ahora!";
                }
                break;
            case 6:
                app = false;
                break;
            default:
                cout << "Ingrese una option valida!!!!";
        }
    } while (app);

}

void menu(){
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|        Tu Banco De Confianza        |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "| 1. Ingresar en tu cuenta            |" << endl;
    cout << "| 2. Crear Cuenta                     |" << endl;
    cout << "| 3. Depositar a Cuenta               |" << endl;
    cout << "| 4. Retirar de Cuenta                |" << endl;
    cout << "| 5. Ver cuentas                      |" << endl;
    cout << "| 6. Salir                            |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
}

void menuCrear(){
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|        Crear Cuenta                 |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
}
void menuCuenta(int accNum){
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|      Cuenta: " << accNum       <<"|"<< endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "| 1. Realizar Retiro                  |" << endl;
    cout << "| 2. Realizar Deposito                |" << endl;
    cout << "| 3. Ver Movimientos                  |" << endl;
    cout << "| 4. Salir                            |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
}

void header(){
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "|               BanSure               |" << endl;
    cout << setfill('-') << setw(40) << "" << endl;
    cout << endl;
}
