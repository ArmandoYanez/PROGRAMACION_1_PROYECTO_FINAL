#ifndef PROYECTO_MENUS_H
#define PROYECTO_MENUS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//Funcion para comprar el puesto de los empleados.
void Comparacion(std::string puesto){

    int Eleccion;
    if (puesto == "GERENTE GENERAL") {
        std::cout << "bienvenido gerente" << std::endl;
        std::cout << "que decea hacer?" << std::endl;
        std::cout << "1. Crear usuario" << std::endl;
        std::cout << "2. Eliminar usuario" << std::endl;
        std::cout << "3. Editar usuario" << std::endl;
        std::cin >> Eleccion;
    }
}

#endif //PROYECTO_MENUS_H
