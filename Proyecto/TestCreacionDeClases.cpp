// Created by Armando Yañez on 14/12/2023.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//Libreria para la creacion de empleados de guadalajara
#include "EmpleadosGuadalajara.h"
#include "FuncionesVerificacionesExtra.h"
int main(){

    GenerarArchivo();
    std::vector<EmpleadoGDL<std::string ,int>> EmpleadosGDL;
    GerenteRecursosHumanos<std::string ,int> GerenteRecursosHumanos;
    GerenteRecursosHumanos.EditarDatos();


    return 0;
}
