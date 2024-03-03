cmake_minimum_required(VERSION 3.23)
project(Banco)

set(CMAKE_CXX_STANDARD 14)

add_executable(Banco main.cpp CuentaBancaria.cpp CuentaBancaria.h EstadosCuenta.cpp EstadosCuenta.h App.cpp App.h)
