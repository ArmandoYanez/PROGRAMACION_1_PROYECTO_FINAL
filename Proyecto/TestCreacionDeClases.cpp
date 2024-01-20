// Created by Armando Yañez on 14/12/2023.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Libreria para la creacion de empleados de guadalajara
#include "EmpleadosGuadalajara.h"
#include "FuncionesVerificacionesExtra.h"
#include "Login.h"
int main(){

    GenerarArchivo();
    Login();

    GerenteRecursosHumanos<std::string ,int> GerenteRecursosHumanos;
    GerenteRecursosHumanos.CreacionEmpleado();
    GerenteRecursosHumanos.EditarDatos();

    return 0;
}
