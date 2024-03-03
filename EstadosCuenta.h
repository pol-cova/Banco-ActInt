//
// Created by Paul Contreras on 26/02/24.
//

#ifndef BANCO_ESTADOSCUENTA_H
#define BANCO_ESTADOSCUENTA_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <utility>
using namespace std;

class EstadosCuenta {
public:
    EstadosCuenta(string tipo, float cantidad){
        tipoMovimiento = std::move(tipo);
        cantidadMovimiento = cantidad;
    }
    string getFechaMovimiento();
    string getTipoMovimiento();
    string getCantidadMovimientoFormat(float cant);
    float getCantidadMovimiento();
private:
    string tipoMovimiento;
    float cantidadMovimiento;
    time_t fecha = time(nullptr);
};


#endif //BANCO_ESTADOSCUENTA_H
