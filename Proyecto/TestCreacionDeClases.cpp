// Created by Armando Yañez on 14/12/2023.
#include <iostream>
#include <string>
#include <vector>

//Libreria para la creacion de empleados de guadalajara
#include "EmpleadosGuadalajara.h"

int main(){

    EmpleadoGDL<std::string,int> EmpleadoUno;
    EmpleadoUno.SetNombre();
    EmpleadoUno.SetDia();
    EmpleadoUno.SetMes();
    EmpleadoUno.SetAnio();
    EmpleadoUno.SetSucursal();

    return 0;
}
