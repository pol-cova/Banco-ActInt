//
// Created by Paul Contreras on 26/02/24.
//

#ifndef BANCO_APP_H
#define BANCO_APP_H

#include "CuentaBancaria.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class App {
public:
    static void Run();
};

// Void menu
void menu();
void menuCrear();
void menuCuenta(int accNum);
void header();


#endif //BANCO_APP_H
