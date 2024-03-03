//
// Created by Paul Contreras on 26/02/24.
//

#include "EstadosCuenta.h"

string EstadosCuenta::getFechaMovimiento() {
    string date = ctime(&fecha);
    return date;
}

string EstadosCuenta::getTipoMovimiento() {
    string tipo = tipoMovimiento;
    return tipo;
}

float EstadosCuenta::getCantidadMovimiento() {
    float cantidad = cantidadMovimiento;
    return cantidad;
}

string EstadosCuenta::getCantidadMovimientoFormat(float cant) {
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

