// Created by Armando Yañez on 14/12/2023.
#include <iostream>
#include <string>
#include <vector>

//Libreria para la creacion de empleados de guadalajara
#include "EmpleadosGuadalajara.h"

int main(){

    std::vector<EmpleadoGDL<std::string ,int>> EmpleadosGDL;
    Jefe Jefe;
    EmpleadosGDL.push_back(Jefe.CreacionEmpleadoGDL());


    return 0;
}
